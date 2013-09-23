#include <iostream>
#include <string.h>
#include "List.h"
#include <assert.h>
using namespace std;

/* Singly linked list class, presently works on contact object pointers only.
   TODO: reimplement as a template
*/

/*Node constructor */
node::node(Contact *c) {
    this->ptr = c ;
    this->next =0;
}

node::~node() {
    if(this->ptr != NULL)
        delete this->ptr;
}

/* List constructor*/
List::List() {
    this->head = NULL;
}


void List::add(Contact *c) {
    node *to_add = new node(c);
    assert(to_add != 0);
    to_add->next = this->head;
    this->head = to_add;
    this->entries++;

}

/* Delete a contact using the first name as parameter */
int  List::del(string toDel) {

    /* Empty List */
    if(this->head == NULL) {
        std::cout<<"List is empty " << std::endl;
        return -1;
    }

    node *it = head;
    node *prev = 0;

    /* First node to be deleted */
    string temp = it->ptr->get_f_name();
    if((temp.compare(toDel))==0) {
        std::cout<<"Deleted first node"<<std::endl;
        head = it->next;
        delete it;
        return 0;
    }

    /* Check in the middle of the list */
    prev = it;
    it = it->next;

    temp.clear();
    while(it != 0) {
        std::cout<<"Looking in the middle of the list:"<< toDel <<" " << temp << std::endl;
        temp = it->ptr->get_f_name();
        if((temp.compare(toDel)) == 0) {
            prev->next = it->next;
            delete it;
            return 0;
        }
        prev = it;
        it = it->next;

    }
    std::cout<<"Not found in the list :" << toDel <<std::endl;
    return -1;
}

int List::size()
{
    return entries;
}

void List::show() {
    node *it = head;
    if(head == NULL) {
        std::cout<<" List is empty "<< std::endl;
        return;
    }
    while(it != NULL) {
        std::cout<< it->ptr->get_f_name() << std::endl;
        it = it->next;

    }
}

/* Searches a contact using the first name as arguement */
Contact * List::search(string str) {
    node *it = this->head;
    string temp;
    while(it!=0) {

        temp = it->ptr->get_f_name();
        if((temp.compare(str))==0) {
            return it->ptr;
        }
        it = it->next;
    }

    return NULL;
}

/* TODO: implement sorting, should be made accept an arguemnt on which fields to sort
   Implement merge sort()
*/
void List::sort() {
#if 0
    /*Simple case when List is null */
    if(head == 0)
        return;

    /* as of now simple implementation */
    int count =0;
    node *it = head;
    node *sec = 0;

    /*get the number of elements in the List */
    while(it->next) {
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

/* reverses the list */
void List::reverse() {

    if(head == 0 || head->next ==0) {
        std::cout<<"List is empty "<< std::endl;
        return;
    }
    node *it = head;
    node *next;
    head = NULL;

    while(it!= NULL) {
        next = it->next;
        it->next = head;
        head = it;
        it = next;
    }
    std::cout<<" AT the end the head is "<< head <<std::endl;
}

/* Destructor, which iteratively deletes all the node and frees th space */
List::~List() {
    node *temp;
    while(this->head !=0) {
        cout << " HEAD --- " << this->head << endl;
        temp = this->head;
        this->head = this->head->next;
        delete(temp);
    }

}

/* Clears the list contents but dont destroy the list */
void List::clr() {
    node *temp;
    std::cout<<"List clear initiated () "<< std::endl;
    while(this->head !=0) {
        temp= this->head;
        this->head = this->head->next;
        delete(temp);
    }
    this->entries =0;
    std::cout<<" List is cleared" <<std::endl;
}











