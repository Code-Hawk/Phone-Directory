#ifndef _CONTACTS_H_
#define _CONTACTS_H_
#include "core.h"
using namespace std;

enum Boolean{ FALSE=0, TRUE};
enum CAPABILITIES{ NONE, CALL, SMS, EMAIL, MESSAGE};
class Contact{
             public:
                    Contact();
                    Contact(string First_name, string Last_name, int **Telephone, int **Mobile,string email, string Location, string Group, CAPABILITIES Abilities
);
                   ~Contact();
                    string get_First_name();
                    void   set_First_name(string First_name);
                    string get_Last_name();
                    void   set_Last_name(string Last_name);
                    int *  get_Telephone();
                    Boolean set_Telephone(int *arr, int size);
                    int *  get_Mobile();
                    Boolean set_Mobile(int *arr, int size);
                    string get_Email_id();
                    void   set_Email_id(string email_id);
                    string get_Location();
                    void   set_Location(string Location);
                    string get_Group();
                    void   set_group(string Group);
                    CAPABILITIES* get_Abilities();
                    void   set_Abilities(CAPABILITIES *);
                                 
		                        
             private:
                    std::string First_name;
                    std::string Last_name;
                    int Telephone[16];
                    int Mobile[16];
    		    std::string Email_id;
                    std::string Location;
                    std::string Group;
                    CAPABILITIES Abilities[5];   
                    
};                    

#endif
