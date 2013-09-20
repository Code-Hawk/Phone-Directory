
#ifndef _LIST_H 
#define _LIST_H
enum Bool{N_FOUND =0, FOUND};
#include<string>
#include"Contact.h"
using namespace std;


class node{
           friend class list;
           public:
                  node(Contact *c);
                 ~node();
           private:
                   Contact *ptr;
                   node *next;
      };
 

class list{
            public:
                           list();
                          ~list(); 
                   void    sort();
                   int     search(string);
                   void    show();
                   void    add(Contact *c);
                   void    del(string);
                   void    append(Contact *c);
                   void    reverse();                   
           private:
                   node *head;
  };             
#endif                   
