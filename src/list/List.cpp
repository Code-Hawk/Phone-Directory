#include <iostream>
#include <string.h>
#include <assert.h>

#include "List.h"
#include "../log/Logger.h"

extern Logger *DEBUGGER;

node::node(Contact *c)
{
	this->ptr = c ;
	this->next = 0;
}

node::~node()
{
	if (this->ptr) {
		delete this->ptr;
	}
}

List::List()
{
	this->head = NULL;
}

void List::add(Contact *c)
{
	node *to_add = new node(c);
	assert(to_add);
	to_add->next = this->head;
	this->head = to_add;
	this->entries++;
}

void List::replace(Contact *c)
{
	node *toRep = new node(c);
	assert(toRep);
	node *it = this->head;
	std::string tosearch = c->get_f_name();
	std::string present;
	if (!this->head) {
		return;
	}

	if (it && (tosearch.compare(it->ptr->get_f_name()) == 0)) {
		toRep->next = it->next;
		this->head = toRep;
		delete it;
		return;
	}

	node *prev = it;
	it = it->next;
	while (it) {
		if (tosearch.compare(it->ptr->get_f_name()) == 0) {
			toRep->next = it->next;
			prev->next = toRep;
			delete it;
			return;
		} else {
			prev = it;
			it = it->next;
		}
	}
}

/* Binary search is not a good idea to search.. since we are storing as linked lists */
int  List::del(std::string toDel)
{
	if (!this->head) {
		return -1;
	}

	node *it = head;
	node *prev = 0;

	std::string temp = it->ptr->get_f_name();
	if (!temp.compare(toDel)) {
		DEBUGGER->log_debug("Deleted first node");
		head = it->next;
		delete it;
		return 0;
	}

	/* Check in the middle of the list */
	prev = it;
	it = it->next;

	temp.clear();
	while (it) {
		temp = it->ptr->get_f_name();
		if ((temp.compare(toDel)) == 0) {
			prev->next = it->next;
			delete it;
			return 0;
		}
		prev = it;
		it = it->next;

	}
	return -1;
}

int List::size()
{
	return entries;
}

void List::show()
{
	DEBUGGER->log_debug("Called in disply all");
	node *it = head;
	if (!head) {
		DEBUGGER->log_debug(" No Contacts in the database ");
		return;
	}

	while (it) {
		std::cout<< it->ptr->get_f_name() << std::endl;
		it = it->next;
	}
}

Contact *List::search(std::string str)
{
	node *it = this->head;
	std::string temp;

	while (it) {
		temp = it->ptr->get_f_name();
		if (!temp.compare(str)) {
			return it->ptr;
		}
		it = it->next;
	}

	return NULL;
}

void List::show(node *n)
{
	node *it = n;

	if (!n) {
		std::cout<<" No Contacts to show as Database is empty "<< std::endl;
		return;
	}

	std::cout <<" First Name  "     << " Last Name" << std::endl;
	while (it) {
		std::cout<< it->ptr->get_f_name() << std::endl;
		it = it->next;
	}
}

/* TODO: implement sorting, should be made accept an arguemnt on which fields to sort
   Implement merge sort()
*/

void List::sort()
{
	head = merge_sort(head);
}

node  *List::merge_sort(node *n)
{
	if (!n || !n->next) {
		return n;
	}

	node *fast = n;
	node *slow = n;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	node *sec_half = slow->next;
	slow->next = NULL;
	return merge(merge_sort(n), merge_sort(sec_half));
}

node *List::merge(node *a, node *b)
{
	node *ret = new node();
	node *temp = ret;

	while (a && b) {
		if (a->ptr->get_f_name().compare(b->ptr->get_f_name()) < 0) {
			ret->next = a;
			a = a->next;
		} else {
			ret->next = b;
			b = b->next;
		}
		ret = ret->next;
	}

	ret->next = (a == NULL)? b :a;
	return temp->next;
}

void List::reverse()
{
	if (!head || !head->next) {
		return;
	}

	node *it = head;
	node *next;
	head = NULL;

	while (it) {
		next = it->next;
		it->next = head;
		head = it;
		it = next;
	}
}

List::~List()
{
	node *temp;
	while (this->head) {
		temp = this->head;
		this->head = this->head->next;
		delete(temp);
	}
}

void List::clr()
{
	node *temp;
	while (this->head) {
		temp= this->head;
		this->head = this->head->next;
		delete(temp);
	}
	this->entries = 0;
}











