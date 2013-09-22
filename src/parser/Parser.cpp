#include "Parser.h"
#include "../list/List.h"
#include "assert.h"
#include <iostream>
#include <vector>
#include <sstream>
#define NO_OF_FIELDS 8
using namespace std;
Parser::Parser(string path){
             this->filepath = path;
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

#if 0
void  Parser::read_all(std::vector<vector<string>> **db)
{
   if(this->file.is_open() && (!this->filepath.empty())){
          string line;
          while(getline(this->file, line)){
             std::cout<< line <<std::endl;
             if(line[0] != '#')
             //db->add(line);
             if(parse_entry(line)==TRUE)
               {
                  std::cout<<" Parsing has been successful"<<std::endl;
            }

      }
  }

}
#endif
void  Parser::read_all(std::string *db)
{
    if(this->file.is_open() && (!this->filepath.empty())){
          string line; // = new string();
          std::cout<< "Inside read_all " << std::endl;
          
          this->file.clear();
          this->file.seekg(0, ios::beg);
          while(getline(this->file,line)){
               	std::cout << line << endl;
                 *db = line;
                 *db++;
   }
   
  }
 return;
}

int Parser::get_no_lines(){
    
     if((!this->file.is_open()) || (this->filepath.empty()))
         return -1;       
     
     this->file.clear();
     this->file.seekg(0, ios::beg);
     int count =0;
     string line;
     while(getline(this->file, line))
          { 
            if((!line.empty())|| (line[0]!='#'))
               count++;
          }
     return count;
   }






std::vector<string> Parser::get_tokens( string line){
std::vector<string> items;
std::stringstream ss(line);
std::string item;
           
            while(std::getline(ss,item,':')){
                  items.push_back(item);
                 }
           return items;
}
            
#if 0                               
Boolean Parser::parse_entry (string line){

std::vector<string> items;
std::stringstream ss(line);
std::string item;
           /* get each indivisual word */
           while(std::getline(ss,item,':')){
                 items.push_back(item);
                } 

     
           if(items.size() == NO_OF_FIELDS ){
              std::cout<<" No of elements are  equal" <<std::endl;
              assert(this->vfy !=0);
              if((!this->vfy->name_vfy(items.at(0))) || (!this->vfy->name_vfy(items.at(1))))
                {  std::cout<<" Names Verification failed"<< std::endl;
                   return FALSE;
                 }
                 
              if((!this->vfy->num_vfy(items.at(2))) || (!this->vfy->num_vfy(items.at(3))))
                {  
                   std::cout<<" Numbers Verification failed"<< std::endl;
                   return FALSE;
                 }
              if(!this->vfy->email_vfy(items.at(4)))
                {  
                   std::cout<<" Email verification failed"<< std::endl;
                   return FALSE;
                }
              if(!this->vfy->loc_vfy(items.at(5))){
                   std::cout<<" location Verifiction failed"<< std::endl;  
                 return FALSE;
                }
          
              if(!this->vfy->loc_vfy(items.at(6))){
                std::cout<<"Group Verification failed" << std::endl; 
                 return FALSE;
                }
              if(!this->vfy->num_vfy(items.at(7))){
                 std::cout<<"Abilities Verification failed"<< std::endl;
                 return FALSE;}

            }
       
          else {
               std::cout<<" Invalid number of entries "<< std::endl;
               return FALSE;
              }
             
           return TRUE;
}
                              
#endif



 



            

