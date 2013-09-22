#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <climits>
#include "Verifier.h"
#include <assert.h>
#include <sstream>
//enum Boolean{ FALSE =0, TRUE};
using namespace std;

void Verifier::trim(string *str){

string::size_type pos = str->find_last_not_of(' ');

if(std::string::npos != pos )
   str->erase(pos+1,str->length()-pos);

 pos = str->find_first_not_of(' ');
 if(pos != std::string::npos)
    str->erase(0,pos);
 
}

Boolean Verifier::name_vfy(string name){
                  trim(&name); 
                  if(name.length() == 0)
                     return FALSE;
                  std::size_t found;
                  /* as of now supports only alphabests */
                  found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
}
                  
Boolean Verifier::num_vfy(string n){
                  trim(&n);                 
                  long num = std::atol(n.c_str());
                 if( num < 0) /* test case fails for -0 */
                    return FALSE;
                 else if( num > LONG_MAX) 
                    return FALSE;
                 else
                    return TRUE;
                           
 }

Boolean Verifier::Abil_vfy(string ab){
                 trim(&ab);
                 if(ab.length()==0)
                   return FALSE;
       
                 int num = std::atoi(ab.c_str());
	         //std::cout<<" Abilities is " << num  <<std::endl;
                 if(num < 0)
                    return FALSE;
                 else if( num > INT_MAX)
                    return FALSE;
                 else
                    return TRUE;
}

Boolean Verifier::email_vfy(string Email){
                trim(&Email);
                if(Email.length()==0)
                   return FALSE;
                
               // std::cout<<" Email is : "<< Email << std::endl; 
                std::size_t found, dot_pos, at_pos;
                found = Email.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890@.ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                if(found != std::string::npos){
                    std::cout<<" EMail is not valid : "<< Email[found] <<std::endl;
                    return FALSE;
                  }
               // std::cout<<" Email Stage 1: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());

                dot_pos = Email.find('.'); 
                if(dot_pos== std::string::npos || dot_pos <2)
                   return FALSE;

               // std::cout<<" Email Stage 2: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                at_pos = Email.find('@');
                if(at_pos == std::string::npos)
                   return FALSE;
               
               // std::cout<<" Email Stage 3: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                if(at_pos < dot_pos)
                   return FALSE;
                
               // std::cout<<" Email Stage 4: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                return TRUE;
}

                      
Boolean Verifier::loc_vfy(string loc){
                  trim(&loc);
                  if(loc.length() == 0){
                    std::cout<<"Location is empty " << std::endl;
                     return FALSE;
                  }
                  std::size_t found;
                  /* as of now supports only alphabests */
                  found = loc.find_first_not_of("abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXYZ ");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
   } 



Boolean Verifier::verify_entry(std::string line, std::vector<string> *items){
              
              //assert(line.empty()!=0);
              assert(items !=0);
              get_tokens(line, items);
           if(items->size() == NO_OF_FIELDS ){
              //std::cout<<" No of elements are  equal" <<std::endl;
              if((!this->name_vfy(items->at(0))) || (!this->name_vfy(items->at(1))))
                {  std::cout<<" Names Verification failed"<< std::endl;
                   return FALSE;
                 }
                 
              if((!this->num_vfy(items->at(2))) || (!this->num_vfy(items->at(3))))
                {  
                   std::cout<<" Numbers Verification failed"<< std::endl;
                   return FALSE;
                 }
              if(!this->email_vfy(items->at(4)))
                {  
                   std::cout<<" Email verification failed"<< std::endl;
                   return FALSE;
                }
              if(!this->loc_vfy(items->at(5))){
                   std::cout<<" location Verifiction failed"<< std::endl;  
                 return FALSE;
                }
          
              if(!this->loc_vfy(items->at(6))){
                std::cout<<"Group Verification failed" << std::endl; 
                 return FALSE;
                }
              if(!this->Abil_vfy(items->at(7))){
                 std::cout<<"Abilities Verification failed"<< std::endl;
                 return FALSE;}

            }
       
          else {
               std::cout<<" Invalid number of entries "<< std::endl;
               return FALSE;
              }
             
           return TRUE;
                             
   
    }        
  
              
            
void Verifier::get_tokens (string line, std::vector<string> *items){
     if(!line.empty()){
        std::stringstream ss(line);
        std::string item;
           
            while(std::getline(ss,item,':')){
                  items->push_back(item);
                 }
}
           return;
}   


                        
                     
                     
                        
