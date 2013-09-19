#include<iostream>
#include "Contact.h"
#include "Parser.h"
#include "list.h"
using namespace std;

int main()
{  
   list *db = new list(); 
   Parser* p = new Parser("/home/yash/PhoneDirectory/Parser.h");
   Parser* pqw = new Parser("");
   p->read_all(db); 
  
   return 0;
}


