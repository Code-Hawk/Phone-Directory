#ifndef _LIST_H
#define _LIST_H

#include "../contact/Contact.h"

enum Bool {N_FOUND =0, FOUND};

class node
{
	friend class List;
public:
	node() {};
	node(Contact *c);
	~node();
private:
	Contact *ptr;
	node *next;
};

class List
{
public:
	List();
	~List();
	void    sort();
	node    *merge_sort(node *n);
	node   *merge(node *, node *);
	Contact *search(std::string);
	void    show();
	void    show(node *n);
	void    add(Contact *c);
	int     del(std::string);
	void    append(Contact *c);
	void    reverse();
	int     size();
	void    clr();
	void    replace(Contact *c);
private:
	node *head;
	int  entries;
};
#endif
