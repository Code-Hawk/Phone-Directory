#ifndef _VERIFIER_H_
#define _VERIFIER_H_
using namespace std;
#include "Contact.h"
#include "core.h"

class Verifier{
               public:
                     Boolean Name_verify(string name);
                     Boolean Telephone_verify(int *tel, int size);
                     Boolean Mobile_verify(int *mob, int size);
                     Boolean Email_verify(string Email);
                     Boolean Group_verify(string name);
                     Boolean Abilities_verify(CAPABILITIES *ab, int size);
               };

                     
                      
#endif                
