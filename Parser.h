#ifndef _PARSER_H
#define _PARSER_H
#include "core.h"
#include <fstream>
using namespace std;
class Parser{
            
           public:  
                  Parser(string filepath);
                  ~Parser();
                  int Parser_start();
                  Boolean read_all();
                  Boolean read_one(string name);
                  Boolean delete_all();
                  Boolean delete_one(string name);
                  Boolean save_all();
                  Boolean save_one(string name);
          private:
                  string filepath;
                  fstream file;
           };

#endif                  
                      
