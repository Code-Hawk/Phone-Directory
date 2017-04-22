#include "Contact.h"
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <climits>
#include <assert.h>
#include <sstream>

#define NUM_CONTACT_ATRIBUTES	8

Contact::Contact(std::vector<std::string> *details)
{
	assert(details->size() == NUM_CONTACT_ATRIBUTES);
	f_name  = details->at(0);
	l_name  = details->at(1);
	tele    = std::atol(details->at(2).c_str());
	mob     = std::atol(details->at(3).c_str());
	email   = details->at(4);
	loc     = details->at(5);
	grp     = details->at(6);
	abil    = details->at(7)[0];
};

Contact::Contact(std::string fname, std::string lname,  long telp, long moble, std::string email_id
                 , std::string ltion, std::string group, char Abil) : f_name(fname),l_name(lname),tele(telp),mob(moble),email(email_id),loc(ltion),
	grp(group)
{

}

void Contact::set_f_name(std::string name)
{
	assert(name.length() > 0);
	this->f_name.assign(name);
}

std::string Contact::get_f_name()
{
	return this->f_name;
}

void Contact::set_l_name(std::string name)
{
	this->f_name.assign(name);
}

std::string Contact::get_l_name()
{
	return this->l_name;
}

long Contact::get_tele()
{
	return this->tele;
}

void Contact::set_tele(long num)
{
	assert(num > 0);
	this->tele = num;
}

long Contact::get_mob()
{
	return this->tele;
}

void Contact::set_mob(long num)
{
	assert(num >0);
	this->mob = num;
}

std::string Contact::get_email()
{
	return this->email;
}

void Contact::set_email(std::string e)
{
	this->email = e;
}

std::string Contact::get_loc()
{
	return this->loc;
}

void Contact::set_loc(std::string ltion)
{
	this->loc.assign(ltion);
}

std::string Contact::get_grp()
{
	return this->grp;
}

void  Contact::set_grp( std::string grp)
{
	this->grp.assign(grp);
}

char Contact::get_Abils()
{
	return this->abil;
}

void Contact::set_Abils(char ab)
{
	int num = ab - '0';
	assert(num > 0);
	this->abil = ab;
}

std::ostream &operator<<(std::ostream &op , const Contact &c)
{
	op<< "First Name :" << c.f_name	<<"\n";
	op<< "Last  Name :" << c.l_name	<<"\n";
	op<< "Telphone   :" << c.tele	<<"\n";
	op<< "Mobile     :" << c.mob	<<"\n";
	op<< "EMail ID   :" << c.email	<<"\n";
	op<< "Group      :" << c.loc	<<"\n";
	op<< "Location   :" << c.grp	<<"\n";
	op<< "Abilities  :" << c.abil	<<"\n";
	return op;
}

std::ostream &operator<<(std::ostream &op , Contact *c)
{
	op<< "First Name :" << c->f_name	<<"\n";
	op<< "Last  Name :" << c->l_name	<<"\n";
	op<< "Telphone   :" << c->tele		<<"\n";
	op<< "Mobile     :" << c->mob		<<"\n";
	op<< "EMail ID   :" << c->email		<<"\n";
	op<< "Group      :" << c->loc		<<"\n";
	op<< "Location   :" << c->grp		<<"\n";
	op<< "Abilities  :" << c->abil		<<"\n";
	return op;
}
