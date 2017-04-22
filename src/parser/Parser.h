#ifndef _PARSER_H
#define _PARSER_H

#include <string>
#include <fstream>

#include "../list/List.h"
#include "../verifier/Verifier.h"

/*  1.Class parser gives the functionality of reading the
*     database contents from the file and building up a
*     raw database.
*   2.It provides the intreface to the other classes
*     to read a single contact or multiple contacts, delete a single or
*     multiple contacts.
*   3.Main idea is to make it general interface so that it can be used
*     with other databases like SQL or other data structures.
*/

class Parser
{
public:
	Parser(std::string filepath);
	~Parser();
	int get_no_lines();
	void read_all(std::string *db);
	Boolean parse_entry(std::string);
	std::vector<std::string> get_tokens(std::string);

private:
	std::string filepath;
	std::fstream file;
};

#endif //_PARSER_H

