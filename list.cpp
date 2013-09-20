#include<iostream>
#include<string.h>
#include "list.h"
#include<assert.h>
using namespace std;

/*Node constructor */
node::node(Contact *c){
     this->ptr = c ;
     this->next =0;
} 

node::~node(){

}

/* list constructor*/
list::list(){
       this->head = 0;
}

void list::add(Contact *c){
         node *to_add = new node(c);
         assert(to_add != 0);
         to_add->next = this->head;
         this->head = to_add;
      }

void list::del(string d){
 
         
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
             std::cout<<"Looking in the middle of the list:"<< d << std::endl; 
               if((it->data.compare(d)) == 0){
                     prev->next = it->next;
                     delete it;
                     return;
               }
               prev = it;
               it = it->next;

           }
       std::cout<<"Not found in the list :" << d <<std::endl;
 }
                           
void list::show(){
       node *it = head;
       if(head == NULL){
          std::cout<<" List is empty "<< std::endl;
          return;
       }
#if 0
       while(it != NULL){
            if(it->next !=  NULL) 
            std::cout<< it << "-->";
            else 
            std::cout<< it->data <<std::endl;
            it = it->next;
            
#endif}
}
                                

int list::search(string str){
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


void list::sort(){
          #if 0 
            /*Simple case when list is null */
            if(head == 0)
               return;

            /* as of now simple implementation */
            int count =0;
            node *it = head;
            node *sec = 0;

           /*get the number of elements in the list */
            while(it->next){
                  count++;
                  it = it->next;
                  }

           /* one element in the list */            
           if(count == 1)
              return;
            /* more than one element */
              node *prev;
        #endif
          }
      

void list::reverse(){
           
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
                                 
                                                          
             









