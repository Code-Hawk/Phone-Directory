#include "Parser.h"
#include "list.h"
#include<iostream>
#include<vector>
#include<sstream>
#define NO_OF_FIELDS 8
using namespace std;
Parser::Parser(string path){
             this->filepath = path;
             this->vfy = new Verifier();
               try{ 
                   if(this->filepath.empty()){
                      throw string("Null file path"); 
                      }
                    else{
                          this->file.open(this->filepath.c_str(), std::fstream::in | std::fstream::out);
                          if(this->file.is_open()){
                          
                          }
                          else
                            std::cout <<"Unable to open the file "<< std::endl;                         } 
                 }
                  catch(string str){
                        std::cout<<" Exception occured"<< str <<std::endl;
                       }
  
       } 
  
Parser::~Parser(){

        this->file.close();
}
                  
int Parser::read_all(list *db)
{
   if(this->file.is_open() && (!this->filepath.empty())){
          string line;
          while(getline(this->file, line)){
             std::cout<< line <<std::endl;
             if(line[0] != '#')
             //db->add(line);
             parse_entry(line);
            }

      }
}
                               
int Parser::parse_entry (string line){

std::vector<string> items;
std::stringstream ss(line);
std::string item;
           /* get each indivisual word */
           while(std::getline(ss,item,':')){
                 items.push_back(item);
                } 

     
           if(items.size() == NO_OF_FIELDS ){
              assert(this->vfy !=0);
              if((!this->vfy->name_vfy(items.at(0))) || (!this->vfy->name_vfy(items.at(1))))
                 return FALSE;
              
              if((!this->vfy->num_vfy(items.at(2))) || (!this->vfy->num_vfy(items.at(3))))
                 return FALSE;
             
              if(!this->vfy->email_vfy(items.at(4)))
                 return FASLE;
              
              if(!this->vfy->loc_vfy(items.at(5)))  
                 return FASLE;
          
              if(!this->vfy->name_vfy(items.at(6)))
                 return FALSE;

              if(!this->vfy->Abil_vfy(items.at(7)))
                 return FALSE;

            }
               
           for(int i = 0; i < items.size(); i++)  
              std::cout<<" Tokens are: " << items.at(i) << std::endl;
            
 }
             return 0;
}
                              




 



            

