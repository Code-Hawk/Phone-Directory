#include<iostream>
#include<string>
#include <cstddef>
#include<algorithm>
enum Boolean{ FALSE =0, TRUE};
using namespace std;

Boolean Verifier::Name_Verfiy(string name){
                  
                  if(name.length() == 0)
                     return FALSE;
                  std::size_t found;

                  found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
}
                  
Boolean Verifier::Number_Verify(char *num, int size){
                 
                 if(size == 0)
                    return FALSE;
                 
                for(int i=0; i<size ;i++)
                   {
                     if(!isDigit(*num)){
                    }
                 }    
                           
 }


Boolean Verifier::Email_Verify(string Email){
                if(Email.length()==0)
                   return FALSE;
                 
                std::size_t found;
                found = Email.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890@.");
                if(found != std::string::npos){
                  }
}               
                        
                     
                     
                        
