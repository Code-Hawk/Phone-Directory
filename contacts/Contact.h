#ifndef _CONTACTS_H_
#define _CONTACTS_H_
#include <string>
#include <vector>
using namespace std;
enum Boolean{ FALSE=0, TRUE};
class Contact{
             public:
                    Contact();
                    Contact(string fname, string lname,  long telp, long moble, string email_id, string ltion, string group, char Ab);
                    Contact(std::vector<string> *records);
                   ~Contact();
                    string get_f_name();
                    void   set_f_name(string first);
                    string get_l_name();
                    void   set_l_name(string last);
                    long  get_tele();
                    void   set_tele(long num);
                    long  get_mob();
                    void   set_mob(long num);
                    string get_email();
                    void   set_email(string email_id);
                    string get_loc();
                    void   set_loc(string Location);
                    string get_grp();
                    void   set_grp(string Group);
                    char   get_Abils();
                    void   set_Abils(char abil);
                                 
		                        
             private:
                    string f_name;/* mandatory field*/
                    string l_name;
                    long tele;
                    long mob;
    		    string email;
                    string loc;
                    string grp;
                    char abil;   
                    
};                    

#endif
