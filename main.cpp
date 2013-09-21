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
   
    Core *_main = Core::get_instance("/home/yash/PhoneDirectory/Contacts.txt");
    assert(_main!=0);
    _main->interface(1,0);
//    _main->interface(RELOAD,0);
//    _main->interface(3,0);
  again:
    string option;
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
 
   if((option_id < -1) || (option_id >7)){
       std::cout<<" Invalid option... " << std::endl;
       option.clear();
       goto again;
     }
   
   if(option_id == -1)
      return -1;
   
  _main->interface(option_id,0);   
   if(option_id != -1)
     goto again;  
//   while(option.compare("0")!=0){
  //         _main->interface(option,0);
   //      std::cin>>option;      
    //      }

       //  _main->interface(DEL,0);
       //  _main->interface(SHOW,0);
       //  string name = string("yash");
       //  _main->interface(SEARCH,&name);
       //  std::cout<<" get the size of the database :  "<< _main->interface(SIZE,0) << std::endl;
//    if(_main->init()<0){
  //  std::cout<<" initiation is not succeeded" <<std::endl;
   //    return -1;
//}
 //  std::cout<< " No of Contacts in database after reading: " << _main->get_no_contacts() << std::endl;
    
   return 0;


}

            
            
     
