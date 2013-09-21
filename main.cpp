#include<iostream>
#include<sstream>
#include "Contact.h"
#include "Parser.h"
#include "list.h"
#include <vector>
#include <algorithm>
#include "Verifier.h"
#include <assert.h>
#include "Core.h"
#include <locale>
#include<string>
using namespace std;

int main()
{  
   
    Core * core = Core::get_instance("/home/yash/PhoneDirectory/Contacts.txt");
    assert(core!=0);
    core->interface(0,0);
    int option_id=0;
 
    while(option_id != -1){
  
    	std::cout<<" Possible options are: "<<std::endl;
    	std::cout<<" LOAD from database : 0 "<< std::endl;
    	std::cout<<" REFRESH database   : 1" << std::endl;
    	std::cout<<" SHOW all contacts  : 2 "<< std::endl;
    	std::cout<<" ADD a contact      : 3 "<< std::endl;
    	std::cout<<" DEL a contact      : 4 "<<std::endl;
    	std::cout<<" SORT the contacts  : 5 "<<std::endl;
    	std::cout<<" SEARCH a contact   : 6 "<<std::endl;
    	std::cout<<" Get no of contacts : 7 "<<std::endl;
    	std::cout<<" Exit Application   : -1"<<std::endl;
   	std::cout<< "Enter the option:";
    	int option_id;
        std::cin>>option_id;
 
   if((option_id < -1) || (option_id > 7)){
       std::cout<<" Invalid option... " << std::endl;
       continue;
    } 
 
   if(option_id == -1)
      return -1;
   
   core->interface(option_id,0);   
   if(option_id != -1)
     continue;
  }
}
            
            
     
