#include<iostream>
#include<string.h>
#include "list.h"
using namespace std;

template <class T>
void list<T>::add(T data){
         node<T> *to_add = new node<T>(data);
         assert(to_add !=0);
         
         to_add->next = head;
         head = to_add;
      }
template<class T>    
void list<T>::del(T data){
 
         node<T> *it = head;
         node<T> *prev = 0;
         
         /* Empty List */
         if(it == NULL)
            return;

         /* First node to be deleted */
          if(it->data == data){
             head = it->next;
             delete it;
             return;
             }    
        /* Middle element */ 
         while(it->next!= 0){
               if(it->data == data){
                  if(prev != 0){
                     prev->next = it->next;
                     delete it;
                     return;
                     }
                }
               prev = it;
               it = it->next;

           }
 }
                           
                

