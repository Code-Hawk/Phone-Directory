#include <iostream>
#include <sstream>
#include "src/contact/Contact.h"
#include "src/parser/Parser.h"
#include "src/list/List.h"
#include <vector>
#include <algorithm>
#include "src/verifier/Verifier.h"
#include <assert.h>
#include "src/core/Core.h"
#include "src/log/Logger.h"
#include <locale>
#include <string>
//#include "src/globals.h" 
#include <limits>
using namespace std;

Logger* DEBUGGER; 
int main()
{ 

    
    DEBUGGER = Logger::logger_get_instance("./log.txt");
    DEBUGGER->log_debug(" Beginning to load into DB ");
    /* Core is a singleton class */
    Core * core = Core::Core_get_instance("data/Contacts.txt");
    assert(core!=0);
    /* Logger is a singleton class */
//    core->interface(0); // no contact with Core class 
 //   Contact ex("yash","yash",234234,23432432,"yash","asdh","asdasd",'3');
 //   cout<< &ex; 
     
    while(1){
	
	//cout << "\n\n\n\033[1;31m**Possible options are: **\033[0m\n";
	cout << "\n\n\n\033[1;31m**Possible options are: **\033[0m\n";
    	//std::cout<< endl << endl << " ** Possible options are: **"<<std::endl;
    	std::cout<<" REFRESH database   : 1,\t";
    	std::cout<<" SHOW all contacts  : 2,\t";
    	std::cout<<" ADD a contact      : 3,\t";
    	std::cout<<" DEL a contact      : 4\t" << endl;
    	std::cout<<" SORT the contacts  : 5,\t";
    	std::cout<<" SEARCH a contact   : 6,\t";
    	std::cout<<" Get no of contacts : 7,\t";
    	std::cout<<" Exit Application   : 8"<<std::endl;
   	std::cout<< "\t ** Enter the option ** : ";
    	int option_id =0;
        while(!(cin >> option_id)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        } 

 
//        std::cin>>option_id;
	cout << endl << endl;
         

   if((option_id < 1) || (option_id > 8)){
       std::cout<<" Invalid option... " << std::endl;
       continue;
    } 
   
   if(option_id == 8){
     delete core;
     delete DEBUGGER;
     break;
 }
   
   core->interface(option_id);   
   if(option_id == 0)
     continue;
  }
}
            
            
     
