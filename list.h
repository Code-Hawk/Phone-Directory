#ifndef _LIST_H 
#define _LIST_H


template <class Type> 
class node{
           friend class list;
           public:
                  node();
                 ~node();
           private:
                   Type data;
                   node<Type> *next;
      };
 

template <class Type >
class list{
            public:
                           list();
                          ~list(); 
                   void    sort();
                   void    search(Type);
                   void    show();
                   void    add(Type);
                   void    del(Type);
                   void    append(Type);
                   
           private:
                   node<Type> *head;
  };             
#endif                   
