#include<iostream>
#include<sstream>
#include "Contact.h"
#include "Parser.h"
#include "list.h"
#include <vector>
#include <algorithm>
#include "Verifier.h"
#include <assert.h>
using namespace std;

enum OPTIONS{START, ADD, DEL, SHOW, EDIT, SORT, SEARCH, STOP};

class core {
            public:
            static core *get_instance(string  file); 
            static int instance; 
                   Parser *psr;
                   Verifier *vfy;
                   ~core();
                   int init();
                   int no_contacts;
                   string *raw_db;
                   list *contacts_db;
            private:  
                   core(const string& filepath);
                   string filepath;
           };
 
int core::instance = 0;


core::core(const string& filepath){
                    
                  psr = new Parser(filepath);
                  vfy = new Verifier();
                  contacts_db = new list();
}

core::~core(){
                 
              core::instance--;
              delete this->psr;
              delete this->vfy;
              delete this->contacts_db;
              delete this->raw_db;
        }

 core *core::get_instance(string file){

                  if(core::instance == 0 && (!file.empty())){
                     core::instance++;
                      return new core(file);
                   }
                  else{
                  std::cout<<"Its a singleton "<< std::endl;
                     return NULL;
                  }
}
                 
           

int main()
{  
   
    core *_main = core::get_instance("/home/yash/PhoneDirectory/Contacts.txt");
    assert(_main!=0);

    if(!_main->init())
       return -1;
    
  //  _main->display_all();
 
      return 0;
}
  
int core::init(){
 
        this->no_contacts = this->psr->get_no_lines();
    
        if(this->no_contacts < 1)
            {
              std::cout<< "Empty file "<< std::endl;
              return -1;
            } 

       this->raw_db = new std::string[this->no_contacts];
       assert(this->raw_db !=0); 
       std::cout<<" No of lines are " << this->no_contacts <<std::endl;
       this->psr->read_all(this->raw_db);
       string *temp= this->raw_db;
       std::vector<string> *tokens = new  std::vector<string>;
       for(int i=0; i<this->no_contacts; i++)
           {
             std::cout<<"String is : "<< temp << std::endl;
             if(!this->vfy->verify_entry(*temp, tokens)){
             std::cout<<" Verification failed " <<std::endl;
             *temp++;
             tokens->clear();
             continue;
           }
           
           if(tokens->size()){
           for(std::vector<string>::iterator it = tokens->begin();it != tokens->end() ; it++)
               {
			 std::cout<< *it << std::endl;
               }
             
            Contact *to_add = new Contact(tokens);
           this->contacts_db->add(to_add);
             //tokens->clear(); 
           }
          temp++;
          
          }
      delete tokens;
   return 0;
}


