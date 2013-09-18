
#ifndef _LIST_H 
#define _LIST_H
enum Bool{N_FOUND =0, FOUND};
#include<string>
using namespace std;


class node{
           friend class list;
           public:
                  node(string d);
                 ~node();
           private:
                   string data;
                   node *next;
      };
 

class list{
            public:
                           list();
                          ~list(); 
                   void    sort();
                   int    search(string);
                   void    show();
                   void    add(string);
                   void    del(string);
                   void    append(string);
                   void    reverse();                   
           private:
                   node *head;
  };             
#endif                   
