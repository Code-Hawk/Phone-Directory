#ifndef _PARSER_H
#define _PARSER_H
#include "list.h"
#include <fstream>
#include "Verifier.h"
using namespace std;
class Parser{
            
           public: 
                  Parser(string filepath);
                  ~Parser();
                  int get_no_lines();
                  void read_all(std::string *db);
                  Boolean parse_entry(std::string);
                 // Boolean read_one(std::string);
                  std::vector<std::string> get_tokens(std::string);
               //   Boolean read_all();
               //   Boolean read_one(string name);
               //   Boolean delete_all();
               //   Boolean delete_one(string name);
               //   Boolean save_all();
               //   Boolean save_one(string name);
          private:
                  string filepath;
                  fstream file;
            };

#endif                  
                      
