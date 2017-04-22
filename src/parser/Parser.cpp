#include "Parser.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "../globals.h"
#include "../log/Logger.h"

#define NO_OF_FIELDS 8

extern Logger *DEBUGGER;

Parser::Parser(std::string path)
{
	this->filepath = path;
	try {
		if (this->filepath.empty()) {
			throw std::string("Exception: Null file path");
		} else {
			this->file.open(this->filepath.c_str(), std::fstream::in | std::fstream::out);
			if (this->file.is_open()) {
				DEBUGGER->log_debug("The database file is opened successfully ");
			} else {
				DEBUGGER->log_debug("Unable to open the file ");
				throw std::string("Exception: Unable to open database file");
			}
		}
	} catch (std::string str) {
		DEBUGGER->log_debug(str);
	}
}

Parser::~Parser()
{
	this->file.close();
}

void  Parser::read_all(std::string *db)
{
	if (this->file.is_open() && (!this->filepath.empty())) {
		std::string line;
		this->file.clear();
		this->file.seekg(0, std::ios::beg);
		while (getline(this->file,line)) {
			std::cout << line << std::endl;
			*db++ = line;
		}
	}
	return;
}

int Parser::get_no_lines()
{
	int count = 0;
	std::string line;

	if ((!this->file.is_open()) || (this->filepath.empty())) {
		return -1;
	}

	this->file.clear();
	this->file.seekg(0, std::ios::beg);

	while (getline(this->file, line)) {
		if ((!line.empty())|| (line[0]!='#')) {
			count++;
		}
	}
	return count;
}

std::vector<std::string> Parser::get_tokens(std::string line)
{
	std::vector<std::string> items;
	std::stringstream ss(line);
	std::string item;

	while (std::getline(ss,item,':')) {
		items.push_back(item);
	}
	return items;
}
