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
using namespace std;


int main()
{  
   
    Core *_main = Core::get_instance("/home/yash/PhoneDirectory/Contacts.txt");
    assert(_main!=0);

    if(_main->init()<0){
    std::cout<<" initiation is not succeeded" <<std::endl;
       return -1;
}
    
   _main->display_all();

      return 0;
}
  


