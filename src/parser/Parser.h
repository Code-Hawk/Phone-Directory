#ifndef _PARSER_H
#define _PARSER_H
#include "../list/List.h"
#include <fstream>
#include "../verifier/Verifier.h"
using namespace std;

/*  1.Class parser gives the functionality of reading the 
*     database contents from the file and building up a 
*     raw database. 
*   2.It provides the intreface to the other classes
*     to read a single contact or multiple contacts, delete a single or 
*     multiple contacts.
*   3.Main idea is to make it general interface so that it can be used 
*     with other databases like SQL or other data structures.
*/

class Parser {

public:
    Parser(string filepath);
    ~Parser();
    int get_no_lines();
    void read_all(std::string *db);
    Boolean parse_entry(std::string);
    // Boolean read_one(std::string); /* TODO */
    std::vector<std::string> get_tokens(std::string);
    //   Boolean read_all(); /* TODO */
    //   Boolean read_one(string name); /* TODO */
    //   Boolean delete_all(); /* TODO */
    //   Boolean delete_one(string name); /* TODO */
    //   Boolean save_all(); /* TODO */
    //   Boolean save_one(string name); /*TODO*/
 
private:
    string filepath;
    fstream file;
};

#endif

