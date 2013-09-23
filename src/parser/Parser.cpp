#include "Parser.h"
#include "../list/List.h"
#include "assert.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "../globals.h"
#define NO_OF_FIELDS 8
using namespace std;

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
               std::cout<<" The database file is opened successfully " << std::endl;
            }
            else
                std::cout <<"Unable to open the file "<< std::endl;
        }
    }
    catch(string str) {
        std::cout<< "Exception: "<< str <<std::endl;
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
        std::cout<< "Inside read_all " << std::endl;

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










