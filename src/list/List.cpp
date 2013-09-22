#include <iostream>
#include <string.h>
#include "List.h"
#include <assert.h>
using namespace std;

/*Node constructor */
node::node(Contact *c){
     this->ptr = c ;
     this->next =0;
} 

node::~node(){
    delete this->ptr;
}

/* List constructor*/
List::List(){
	this->head = NULL;       
}
void List::add(Contact *c){
         node *to_add = new node(c);
         assert(to_add != 0);
         to_add->next = this->head;
         this->head = to_add;
         this->entries++;
 
      }

void List::del(string d){
#if 0 
         
         /* Empty List */
         if(head == NULL){
            std::cout<<"List is empty " << std::endl; 
            return;
           }
           
         node *it = head;
         node *prev = 0;
 
         /* First node to be deleted */
          if((it->data.compare(d))==0){
             std::cout<<"Deleted first node"<<std::endl;
             head = it->next;
             delete it;
             return;
             }

         /* start from the second element */
          prev = it;
          it = it->next;

        /* Middle element */ 
         while(it != 0){
             std::cout<<"Looking in the middle of the List:"<< d << std::endl; 
               if((it->data.compare(d)) == 0){
                     prev->next = it->next;
                     delete it;
                     return;
               }
               prev = it;
               it = it->next;

           }
       std::cout<<"Not found in the List :" << d <<std::endl;
#endif
 }

int List::size()
{
   return entries;
 }
                           
void List::show(){
       node *it = head;
       if(head == NULL){
          std::cout<<" List is empty "<< std::endl;
          return;
       }
       while(it != NULL){
            std::cout<< it->ptr->get_f_name() << std::endl;
            it = it->next;
            
      }
}
                                

int List::search(string str){
           node *it = this->head;

           if(it == NULL){
              std::cout<<" List is empty" << std::endl;
              return -1;
             }

           while(it != NULL){
                // if((it->idata.e(str)) == 0)
                    return 0;
                 it = it->next; 
              }
            return -1;
               
}


void List::sort(){
          #if 0 
            /*Simple case when List is null */
            if(head == 0)
               return;

            /* as of now simple implementation */
            int count =0;
            node *it = head;
            node *sec = 0;

           /*get the number of elements in the List */
            while(it->next){
                  count++;
                  it = it->next;
                  }

           /* one element in the List */            
           if(count == 1)
              return;
            /* more than one element */
              node *prev;
        #endif
          }
      

void List::reverse(){
           
      if(head == 0 || head->next ==0){
         std::cout<<"List is empty "<< std::endl;
         return;
     } 
      node *it = head;
      node *next;
      head = NULL;
      
      while(it!= NULL){
              next = it->next;
              it->next = head;
              head = it;
              it = next;
          }
       std::cout<<" AT the end the head is "<< head <<std::endl;
     }                

List::~List(){
    node *temp;
    while(this->head !=0){
          temp = this->head;
          this->head = this->head->next;
          delete(temp);
        }

}

void List::clr(){
  node *temp;
  std::cout<<"List clear initiated () "<< std::endl;
   while(this->head !=0){
           temp= this->head;
           this->head = this->head->next;
           delete(temp);
        }
std::cout<<" List is cleared" <<std::endl; 
}                                 
                                                          
             









