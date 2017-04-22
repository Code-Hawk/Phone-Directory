#ifndef _VERIFIER_H_
#define _VERIFIER_H_
#include "../contact/Contact.h"
#include <vector>
#include <string>

#define NO_OF_FIELDS	8

class Verifier
{
public:
	Verifier() {};
	~Verifier() {};
	Boolean name_vfy(std::string name);
	Boolean num_vfy(std::string num);
	Boolean email_vfy(std::string em);
	Boolean loc_vfy(std::string loc);
	Boolean Abil_vfy(std::string abil);
	Boolean verify_entry(std::string line, std::vector<std::string> *items);
	void get_tokens(std::string line, std::vector<std::string> *items , char delim);
	void trim(std::string *str);
};

#endif //_VERIFIER_H_
