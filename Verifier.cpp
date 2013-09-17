#include<iostream>
#include<string>
using namespace std;

Boolean Verifier::Name_Verfiy(string name){
                  
                  if(name.len == 0)
                     return FALSE;
                  std::size_t found;
                  if(found = name.first_find_not_of("abcdefghijklmnopqrstuvwxyz")   
