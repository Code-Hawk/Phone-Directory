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
   
    Core * core = Core::get_instance("./Contacts.txt");
    assert(core!=0);
    core->interface(0,0);
    int option_id=0;
 
    while(option_id != -1){
  
    	std::cout<< endl << endl << " ** Possible options are: **"<<std::endl;
    	std::cout<<" LOAD from database : 0,\t";
    	std::cout<<" REFRESH database   : 1,\t";
    	std::cout<<" SHOW all contacts  : 2,\t";
    	std::cout<<" ADD a contact      : 3,\t";
    	std::cout<<" DEL a contact      : 4\t" << endl;
    	std::cout<<" SORT the contacts  : 5,\t";
    	std::cout<<" SEARCH a contact   : 6,\t";
    	std::cout<<" Get no of contacts : 7,\t";
    	std::cout<<" Exit Application   : -1"<<std::endl;
   	std::cout<< "\t ** Enter the option ** : ";
    	int option_id;
        std::cin>>option_id;
	cout << endl << endl;
 
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
            
            
     
