#ifndef _VERIFIER_H_
#define _VERIFIER_H_
#include "../contact/Contact.h"
#include <vector>
#define NO_OF_FIELDS 8
using namespace std;
class Verifier{
               public:
                     Verifier(){};
                     ~Verifier(){};
                     Boolean name_vfy(string name);
                     Boolean num_vfy(string num);
                     Boolean email_vfy(string em);
                     Boolean loc_vfy(string loc);
                     Boolean Abil_vfy(string abil);
                     Boolean verify_entry(std::string line, std::vector<string> *items);
                     void get_tokens(string line, std::vector<string> *items); 
                     void trim(string *str);

  };

                     
                      
#endif                