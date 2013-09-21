#include "Core.h"
using namespace std;

int Core::instance = 0;

int Core::interface(int opt, void *arg){
 
  switch(opt){
   case 0:
           this->init();
           return 0;
   case 1: 
            std::cout<<"Calling reinit() "<< this->no_contacts<<std::endl;
            this->reinit();   
            return 0;
   case 3: 
           //if(arg != NULL){
             //Contact *c = (Contact *)arg;
             return  this->add_contact(0);
             //}
           // else return -1;
   case 4:
            //if(arg != NULL){
             // string *name = (string *)arg;
              return this->del_contact(0);
             // }
             //else return -1;  
   case 2: 
             this->display_all();
             return 0;
   case 5:
             this->sort_contacts();
             return 0;
   case 6:
              if(arg!= NULL){
               string *name = (string *)arg;
               return this->search_contact(name);
               }
              else return -1;
   case -1:
             return this->stop();
     
   case 7:
             return this->get_no_contacts();
       
     default:
           std::cout<< "Not a valid operation"<<std::endl;
           return -1;
       
}
}


Core::Core(const string& filepath){
                    
                  psr = new Parser(filepath);
                  vfy = new Verifier();
                  contacts_db = new list();
}

Core::~Core(){
                 
              Core::instance--;
              delete this->psr;
              delete this->vfy;
              delete this->contacts_db;
              delete this->raw_db;
        }


 Core *Core::get_instance(string file){

                  if(Core::instance == 0 && (!file.empty())){
                    Core::instance++;
                      return new Core(file);
                   }
                  else{
                  std::cout<<"Its a singleton "<< std::endl;
                     return NULL;
                  }
}


int Core::init(){
          
       std::cout<<" Reinitialising the Database "<< std::endl;
        this->no_contacts = this->psr->get_no_lines();
    
        if(this->no_contacts < 1)
            {
              std::cout<< "Empty file "<< std::endl;
              return -1;
            } 
       std::cout<<" Reinitialising the Database "<< std::endl;
       this->raw_db = new std::string[this->no_contacts];
       assert(this->raw_db !=0); 
       std::cout<<" No of lines are " << this->no_contacts <<std::endl;
       this->psr->read_all(this->raw_db);
       string *temp= this->raw_db;
       std::vector<string> *tokens = new  std::vector<string>;
       for(int i=0; i<this->no_contacts; i++)
           {
	//	     std::cout<<"String is : "<< *temp << std::endl;
             if(!this->vfy->verify_entry(*temp, tokens)){
             std::cout<<" Verification failed for line :" <<i <<std::endl;
             *temp++;
             tokens->clear();
             continue;
           }
           
           if(tokens->size()){
         /*  for(std::vector<string>::iterator it = tokens->begin();it != tokens->end() ; it++)
          *     {
	  *		 std::cout<< *it << std::endl;
               } */
             
            Contact *to_add = new Contact(tokens);
            this->contacts_db->add(to_add);
             //tokens->clear(); 
           }
          tokens->clear(); 
          temp++;
          
          }
      delete tokens;
      std::cout<<" Successfully initialised "<< std::endl;
   return 0;
}

int Core::get_no_contacts(){
         
         if(this->contacts_db !=0);
         return this->contacts_db->size();
}


void Core::display_all(){
            
      //      if(this->contacts_db == 0)
        //       return;
             std::cout<<"Showing all available contacts"<< std::endl;
             this->contacts_db->show();
}


int Core::reload(){
 
          std::cout <<" Reload function called " << std::endl;
          return 0;
 }

int Core::add_contact( Contact *c){

         std::cout<<"Add Contact is called"<< std::endl;
         return 0;
}

int Core::del_contact(string *name) {
       std::cout<<" Delete Contact is called"<< std::endl;
       return 0;
}

void Core::sort_contacts(){
      std::cout<<" Sort_contacts called"<< std::endl;
}

int Core::search_contact(string *name){

    std::cout<<" Search Contact is called" << std::endl;
    return 0;
}

int Core::stop(){
    std::cout<<" Stop is called: Application ending "<<std::endl;
    return -1;

}

int edit_contact(string *name){

     std::cout<<" Contact edit has been called" << std::endl;
     return 0;
 }


int Core::reinit(){
	cout << "inside Core::reinit() " << endl; 
        this->no_contacts = this->psr->get_no_lines();
	cout << "Core::reinit() -- set the number of contacts " << endl; 
        this->contacts_db->clr();
	cout << "Core::reinit() -- deleted the contact db " << endl; 
        this->contacts_db = new list(); 
	cout << "Core::reinit() -- new list created " << endl; 
        if(this->no_contacts < 1)
            {
              std::cout<< "Empty file "<< std::endl;
              return -1;
            } 
       delete(this->raw_db); 
	cout << "Core::reinit() -- deleted raw db " << endl; 
       this->raw_db = new std::string[this->no_contacts];
       assert(this->raw_db !=0); 
       std::cout<<" No of lines are " << this->no_contacts <<std::endl;
       this->psr->read_all(this->raw_db);
       string *temp= this->raw_db;
       std::vector<string> *tokens = new  std::vector<string>;
       for(int i=0; i<this->no_contacts; i++)
           {
	//	     std::cout<<"String is : "<< *temp << std::endl;
             if(!this->vfy->verify_entry(*temp, tokens)){
             std::cout<<" Verification failed for line :" <<i <<std::endl;
             *temp++;
             tokens->clear();
             continue;
           }
           
           if(tokens->size()){
         /*  for(std::vector<string>::iterator it = tokens->begin();it != tokens->end() ; it++)
          *     {
	  *		 std::cout<< *it << std::endl;
               } */
             
            Contact *to_add = new Contact(tokens);
            this->contacts_db->add(to_add);
             //tokens->clear(); 
           }
          tokens->clear(); 
          temp++;
          
          }
      delete tokens;
   return 0;
 } 
    
       






        
          
