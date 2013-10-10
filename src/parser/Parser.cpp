#include "Parser.h"
#include "../list/List.h"
#include "assert.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "../globals.h"
#include "../log/Logger.h"
#define NO_OF_FIELDS 8

using namespace std;

extern Logger* DEBUGGER;
/* Constructor -- Throws exception if the database file path is not given */

Parser::Parser(string path) {
    
   this->filepath = path;
    try {
        if(this->filepath.empty()) {
            throw string("Null file path");
        }
        else {
            this->file.open(this->filepath.c_str(), std::fstream::in | std::fstream::out);
            if(this->file.is_open()) {
               DEBUGGER->log_debug(" The database file is opened successfully ");
            }
            else
                DEBUGGER->log_debug("Unable to open the file ");
        }
    }
    catch(string str) {
        DEBUGGER->log_debug( "Exception: ");
    }

}

/* Destructor */
Parser::~Parser() {
    this->file.close();
}

/* Parser Interface to the db which reads all the database contents */
void  Parser::read_all(std::string *db)
{
    if(this->file.is_open() && (!this->filepath.empty())) {
        string line; // = new string();
        DEBUGGER->log_debug("Inside read_all ");

        this->file.clear();
        this->file.seekg(0, ios::beg);
        while(getline(this->file,line)) {
            std::cout << line << endl;
            *db++ = line;
        }

    }
    return;
}

/* Returns the number of valid lines(not starting from #) in the database file.
   This function will be called, inorder to know the maximum number of possible 
   contacts, so that we can allocate the the raw database accordingly. */
  
int Parser::get_no_lines() {

    if((!this->file.is_open()) || (this->filepath.empty()))
        return -1;

    this->file.clear();
    this->file.seekg(0, ios::beg);
    int count =0;
    string line;
    while(getline(this->file, line))
    {
        if((!line.empty())|| (line[0]!='#'))
            count++;
    }
    return count;
}

/* This function tokenises each entry of database file and returns the tokens
   the form of an vector of strings to the caller */

std::vector<string> Parser::get_tokens( string line) {
    std::vector<string> items;
    std::stringstream ss(line);
    std::string item;

    while(std::getline(ss,item,':')) {
        items.push_back(item);
    }
    return items;
}










