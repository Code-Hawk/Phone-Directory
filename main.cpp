#include<iostream>
#include "Contact.h"
#include "Verifier.h"
#include "Parser.h"
#include "list.h"
using namespace std;

int main()
{  
   Contact c; 
   #if 0 
   list *db = new list();
   db->add("yash");
   db->add("yashavanth"); 
   std::cout<<" Inside Main" << endl;
   db->show();
   std::cout <<" Searching for yash : Found ="<< db->search("yashava") <<endl;
   db->del("yashava");
   db->reverse();
   db->show();
   #endif
   return 0;
}


