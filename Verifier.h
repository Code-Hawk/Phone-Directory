#ifndef _VERIFIER_H_
#define _VERIFIER_H_
using namespace std;
#include "Contact.h"
#include "core.h"

class Verifier{
               public:
                     Verifier();
                     ~Verifier();
                     Boolean name_vfy(string name);
                     Boolean num_vfy(long tel);
                     Boolean email_vfy(string em);
                     Boolean loc_vfy(string loc);
                    // Boolean abil_vfy(char ab); /* required ? */
               };

                     
                      
#endif                
