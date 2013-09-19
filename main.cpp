#include<iostream>
#include<sstream>
#include "Contact.h"
#include "Parser.h"
#include "list.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{  
   list *db = new list(); 
   Parser* p = new Parser("/home/yash/PhoneDirectory/Contacts.txt");
   Parser* pqw = new Parser("");
   p->read_all(db);

   return 0;
}


