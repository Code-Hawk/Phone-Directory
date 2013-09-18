#ifndef _VERIFIER_H_
#define _VERIFIER_H_
using namespace std;
#include "Contact.h"
#include "core.h"

class Verifier{
               public:
                     Boolean name_vfy(string name);
                     Boolean tel_vfy(long tel);
                     Boolean mob_vfy(long mob);
                     Boolean email_vfy(string em);
                     Boolean grp_vfy(string grp);
                     Boolean abil_vfy(char ab);
               };

                     
                      
#endif                
