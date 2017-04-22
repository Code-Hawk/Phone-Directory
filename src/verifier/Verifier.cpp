#include <iostream>
#include <cstddef>
#include <algorithm>
#include <climits>
#include <assert.h>
#include <sstream>

#include "Verifier.h"
#include "../globals.h"
#include "../log/Logger.h"

extern Logger *DEBUGGER;

void Verifier::trim(std::string *str)
{
	std::string::size_type pos = str->find_last_not_of(' ');

	if (std::string::npos != pos ) {
		str->erase(pos+1,str->length()-pos);
	}

	pos = str->find_first_not_of(' ');
	if (pos != std::string::npos) {
		str->erase(0,pos);
	}
}

Boolean Verifier::name_vfy(std::string name)
{
	trim(&name);
	if (name.length() == 0) {
		return FALSE;
	}
	std::size_t found;
	/* as of now supports only alphabests */
	found = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
	if (found != std::string::npos) {
		return FALSE;
	}

	return TRUE;
}

Boolean Verifier::num_vfy(std::string n)
{
	trim(&n);

	std::size_t found;
	/* only numbers */
	found = n.find_first_not_of("-1234567890 ");
	if (found != std::string::npos) {
		return FALSE;
	}

	long num = std::atol(n.c_str());
	if ( num < 0) { /* test case fails for -0 */
		return FALSE;
	} else if ( num > LONG_MAX) {
		return FALSE;
	} else {
		return TRUE;
	}
}

Boolean Verifier::Abil_vfy(std::string ab)
{
	trim(&ab);
	if (ab.length()==0) {
		return FALSE;
	}

	int num = std::atoi(ab.c_str());
	if (num < 0) {
		return FALSE;
	} else if ( num > INT_MAX) {
		return FALSE;
	} else {
		return TRUE;
	}
}

Boolean Verifier::email_vfy(std::string Email)
{
	trim(&Email);
	if (Email.length()==0) {
		return FALSE;
	}

	size_t found = Email.find_first_not_of("_abcdefghijklmnopqrstuvwxyz1234567890@.ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	if (found != std::string::npos) {
		return FALSE;
	}

	size_t at_count = std::count(Email.begin(), Email.end(), '@');

	if (at_count!=1) {
		return FALSE;
	}

	std::vector<std::string> token;
	get_tokens(Email, &token,'@');
	if (token.size() < 2) {
		return FALSE;
	}

	if (token.at(1).empty()|| token.at(0).empty()) {
		return FALSE;
	}
	found = token.at(1).find_first_not_of(".abcdefghijklmnopqrstuvwxyz");
	if (found != std::string::npos) {
		return FALSE;
	}

	size_t dot_cnt = std::count(token.at(1).begin(), token.at(1).end(),'.');

	if ((dot_cnt!=1) || (token.at(1)[0] == '.') || (token.at(1)[token.at(1).length()-1] == '.')) {
		return FALSE;
	}

	return TRUE;
}

/* Location is allowed only with alphabets, no numbers and special characters */
Boolean Verifier::loc_vfy(std::string loc)
{
	trim(&loc);
	if (loc.length() == 0) {
		DEBUGGER->log_debug ("Location is empty ");
		return FALSE;
	}

	std::size_t found;
	/* as of now supports only alphabests */
	found = loc.find_first_not_of("abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXYZ ");
	if (found != std::string::npos) {
		return FALSE;
	}

	return TRUE;
}

/* Main function calls the other functions on each field basis and
   returns FALSE, even if one of the entry is not valid
   Always assumes that, entry in the file are of the order --
   First Name : Last Name: Telephone : Mobile : Email ID : Location : Group : Abilities
*/
Boolean Verifier::verify_entry(std::string line, std::vector<std::string> *items)
{
	assert(items !=0);
	char ch =':';
	get_tokens(line, items,ch);

	if (items->size() == NO_OF_FIELDS) {

		for ( int i=0; i< 8; i++) {
			trim(&items->at(i));
		}

		DEBUGGER->log_debug ("Verification started ");
		if ((!this->name_vfy(items->at(0))) || (!this->name_vfy(items->at(1)))) {
			DEBUGGER->log_debug(" Names Verification failed");
			return FALSE;
		}

		if ((!this->num_vfy(items->at(2))) || (!this->num_vfy(items->at(3)))) {
			DEBUGGER->log_debug(" Numbers Verification failed");
			return FALSE;
		}

		if (!this->email_vfy(items->at(4))) {
			DEBUGGER->log_debug(" Email verification failed");
			return FALSE;
		}

		if (!this->loc_vfy(items->at(5))) {
			DEBUGGER->log_debug(" location Verifiction failed");
			return FALSE;
		}

		if (!this->loc_vfy(items->at(6))) {
			DEBUGGER->log_debug("Group Verification failed");
			return FALSE;
		}

		if (!this->Abil_vfy(items->at(7))) {
			DEBUGGER->log_debug("Abilities Verification failed");
			return FALSE;
		}

	} else {
		DEBUGGER->log_debug(" Invalid number of entries ");
		return FALSE;
	}

	return TRUE;
}

void Verifier::get_tokens (std::string line, std::vector<std::string> *items, char delim)
{
	if (!line.empty()) {
		std::stringstream ss(line);
		std::string item;

		while (std::getline(ss,item,delim)) {
			items->push_back(item);
		}
	}
	return;
}
