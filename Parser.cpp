#include "Parser.h"
#include "list.h"
#include<iostream>
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
                           # if 0 
                            string line;
                           //  std::cout<<"File is opened :" <<path <<std::endl;
                             while(getline(this->file,line)){
                                
                                   std::cout<< line << std::endl;
                              
                             }
                          #endif
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
             db->add(line);
            }

      }
}
                               
int Parser::parse_entry (string line){

    

            

