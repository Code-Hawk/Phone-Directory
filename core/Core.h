#include<iostream>
#include<sstream>
#include "Contact.h"
#include "Parser.h"
#include "list.h"
#include <vector>
#include <algorithm>
#include "Verifier.h"
#include <assert.h>
using namespace std;

enum OPTIONS{LOAD=0,RELOAD, ADD, DEL, SHOW, SORT, SEARCH, STOP, SIZE};
 
class Core {
            public:
            static Core *get_instance(string  file); 
            static int instance; 
                   Parser *psr;
                   Verifier *vfy;
                   ~Core();
                   int interface(int opt, void *arg);
                   int init();
                   int reinit();
                   int no_contacts;
                   string *raw_db;
                   list *contacts_db;
           private:
                   void display_all();
                   int get_no_contacts();
                   int reload();
                   int add_contact(Contact *);
                   int del_contact(string *);
                   void sort_contacts();
                   int search_contact(string *);
                   int stop();
                   int edit_contact(string *);  
                   Core(const string& filepath);
                   string filepath;
                                       
           };
