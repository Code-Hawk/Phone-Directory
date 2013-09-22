#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <climits>
#include "Verifier.h"
#include <assert.h>
#include <sstream>
#include "../globals.h"
//enum Boolean{ FALSE =0, TRUE};
using namespace std;

Verifier::~Verifier(){
  cout << " Verifier: Destructor called" << endl;
}


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
                  found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
}
                  
Boolean Verifier::num_vfy(string n){
                  trim(&n); 
                                   
                  std::size_t found;
                  /* only numbers */
                  found = n.find_first_not_of("-1234567890 ");
                  if(found != std::string::npos)
                     return FALSE;

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
                
                std::cout << " Email is : " << Email << std::endl; 
               /* Email supports only . _ @ characters and numbers only */ 
                size_t found = Email.find_first_not_of("_abcdefghijklmnopqrstuvwxyz1234567890@.ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                
                if(found != std::string::npos){
                    std::cout<<" Email is not valid : "<< Email[found] <<std::endl;
                    return FALSE;
                  }
                
               /* Count the number of @ -- only one allowed */
                size_t at_count = std::count(Email.begin(), Email.end(), '@');
                std::cout << " No of @'s " << at_count << std::endl;
                
                if(at_count!=1)
                   return FALSE;
                /* get the second part of the email - after @ character */  
                std::vector<string> token;
                get_tokens(Email, &token,'@');
                /* Email should not be @terminated */
                if(token.size() < 2)
                   return FALSE;
   
                cout << "Tokens are" <<  token.at(0)  << " " << token.at(1) <<endl;    
                /* If either of the tokens are empty , then not valid */
                if(token.at(1).empty()|| token.at(0).empty()){
                   cout << " Email ends with @ -- not valid " << endl;
                   return FALSE;
                 }
                /* Word after @ should not contain any special characters and numbers and Upper case letters */
                found = token.at(1).find_first_not_of(".abcdefghijklmnopqrstuvwxyz");
                if(found != std::string::npos)
                   return FALSE;
                /* example@ddf.dfdf.dfdf.dfdf -- not suppoerted */  
                size_t dot_cnt = std::count(token.at(1).begin(), token.at(1).end(),'.');
                std::cout<<" No of dot counts " << dot_cnt <<std::endl;
                
                /* examples@.sff example@sdfdsf. are not supported */  
                std::cout<<" Character in last position is : " << token.at(1)[token.at(1).length()-1] << std::endl;
                if((dot_cnt!=1) || (token.at(1)[0] == '.') || (token.at(1)[token.at(1).length()-1] == '.'))
                    return FALSE;   
           
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
              char ch =':';
              get_tokens(line, items,ch);
              
           if(items->size() == NO_OF_FIELDS ){
              
               for( int i=0; i< 8; i++)
                    trim(&items->at(i));

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
  
              
            
void Verifier::get_tokens (string line, std::vector<string> *items, char delim){
     if(!line.empty()){
        std::stringstream ss(line);
        std::string item;
           
            while(std::getline(ss,item,delim)){
                  items->push_back(item);
                 }
             }
           return;
}   


                        
                     
                     
                        
