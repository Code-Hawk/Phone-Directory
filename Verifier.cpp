#include<iostream>
#include<string>
#include <cstddef>
#include<algorithm>
#include<climits>
#include "Verifier.h"
//enum Boolean{ FALSE =0, TRUE};
using namespace std;

Verifier::Verifier(){

}

Verifier::~Verifier(){

}



Boolean Verifier::name_vfy(string name){
                  
                  if(name.length() == 0)
                     return FALSE;
                  std::size_t found;
                  /* as of now supports only alphabests */
                  found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
}
                  
Boolean Verifier::num_vfy(long num){
                 
                 if( num < 0) /* test case fails for -0 */
                    return FALSE;
                 else if( num > LONG_MAX) 
                    return FALSE;
                 else
                    return TRUE;
                           
 }


Boolean Verifier::email_vfy(string Email){
                
                if(Email.length()==0)
                   return FALSE;
                
                std::cout<<" Email is : "<< Email << std::endl; 
                std::size_t found, dot_pos, at_pos;
                found = Email.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890@.ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                if(found != std::string::npos){
                    std::cout<<" EMail is not valid : "<< Email[found] <<std::endl;
                    return FALSE;
                  }
                std::cout<<" Email Stage 1: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());

                dot_pos = Email.find('.'); 
                if(dot_pos== std::string::npos || dot_pos <2)
                   return FALSE;

                std::cout<<" Email Stage 2: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                at_pos = Email.find('@');
                if(at_pos == std::string::npos)
                   return FALSE;
               
                std::cout<<" Email Stage 3: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                if(at_pos < dot_pos)
                   return FALSE;
                
                std::cout<<" Email Stage 4: " << Email <<std::endl;
                std::reverse(Email.begin(), Email.end());
                return TRUE;
}

                      
Boolean Verifier::loc_vfy(string loc){
                  
                  if(loc.length() == 0)
                     return FALSE;
                  std::size_t found;
                  /* as of now supports only alphabests */
                  found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
                  if(found != std::string::npos)
                     return FALSE;
                  
                  return TRUE;
    



                             
   
            
  
              
            
   


                        
                     
                     
                        
