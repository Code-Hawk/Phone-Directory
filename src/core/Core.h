#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<limits>

#include "../contact/Contact.h"
#include "../parser/Parser.h"
#include "../list/List.h"
#include "../log/Logger.h"
#include "../verifier/Verifier.h"

class Core
{
public:
	static Core *Core_get_instance(string file);
	static int instance;
	Parser *psr;
	Verifier *vfy;
	~Core();
	int interface(int opt);
	int no_contacts;
	string *raw_db;
	List *contacts_db;

private:
	int init();
	void display_all();
	int get_no_contacts();
	int reinit();
	int add_contact();
	int del_contact();
	int edit_contact(Contact *c);
	void sort_contacts();
	int search_contact();
	int stop();
	int edit_contact(string *);
	Core(const string &filepath);
	string filepath;
};
