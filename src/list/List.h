#ifndef _LIST_H 
#define _LIST_H
enum Bool{N_FOUND =0, FOUND};
#include <string>
#include "../contact/Contact.h"
using namespace std;


class node{
           friend class List;
           public:
                  node(Contact *c);
                 ~node();
           private:
                   Contact *ptr;
                   node *next;
      };
 

class List{
            public:
                           List();
                          ~List(); 
                   void    sort();
                   Contact * search(string);
                   void    show();
                   void    add(Contact *c);
                   int     del(string);
                   void    append(Contact *c);
                   void    reverse();    
                   int     size(); 
                   void    clr();               
           private:
                   node *head;
                   int  entries;
  };             
#endif                   
