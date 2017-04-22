#ifndef _CONTACTS_H_
#define _CONTACTS_H_

#include <string>
#include <vector>

enum Boolean {FALSE = 0, TRUE};

class Contact
{
	friend std::ostream &operator<<(std::ostream &os, const Contact &c);
	friend std::ostream &operator<<(std::ostream &os, Contact *);

public:

	Contact() { };
	Contact(std::string fname, std::string lname,  long telp, long moble,
			std::string email_id, std::string ltion, std::string group, char Ab);
	Contact(std::vector<std::string> *records);
	~Contact() { };
	std::string get_f_name();
	void   set_f_name(std::string first);
	std::string get_l_name();
	void   set_l_name(std::string last);
	long   get_tele();
	void   set_tele(long num);
	long   get_mob();
	void   set_mob(long num);
	std::string get_email();
	void   set_email(std::string email_id);
	std::string get_loc();
	void   set_loc(std::string Location);
	std::string get_grp();
	void   set_grp(std::string Group);
	char   get_Abils();
	void   set_Abils(char abil);

private:
	std::string f_name;/* mandatory field*/
	std::string l_name;
	long tele;
	long mob;
	std::string email;
	std::string loc;
	std::string grp;
	char abil;
};

#endif //_CONTACTS_H_
