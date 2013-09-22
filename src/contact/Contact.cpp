#include "Contact.h"
#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <climits>
//#include <Verifier.h>
#include <assert.h>
#include <sstream>
#define NO_OF_FIELDS 8

Contact::Contact(){
};

Contact::Contact(std::vector<string> *details) {

              
             assert(details->size() == NO_OF_FIELDS);
             f_name  = details->at(0);
             l_name  = details->at(1);
             tele    = std::atol(details->at(2).c_str());
             mob     = std::atol(details->at(3).c_str());
             email   = details->at(4);
             loc     = details->at(5);
             grp     = details->at(6);
             abil    = details->at(7)[0];  
};


Contact::Contact(string fname, string lname,  long telp, long moble, string email_id
 , string ltion, string group, char Abil) : f_name(fname),l_name(lname),tele(telp),mob(moble),email(email_id),loc(ltion),grp(group)
   { 
    
	//cout << "Member initialed Constructor " << email.length() << endl;
} 

Contact::~Contact(){

cout << "Contact: Destructor called " << endl;
}

void Contact::set_f_name(string name){
                 assert(name.length() > 0);
                 this->f_name.assign(name);
               }

string Contact::get_f_name(){
                   return this->f_name;
                 }


void Contact::set_l_name(string name){
                 this->f_name.assign(name);
               }

string Contact::get_l_name(){
                    return this->l_name;
                }

long Contact::get_tele(){
                   return this->tele;
                }
 
void Contact::set_tele(long num){
                   assert(num >0);
                   this->tele = num;
                }

std::ostream& operator<<(std::ostream& op , const Contact& c){
         op<< "First Name :" << c.f_name <<"\n";
         op<< "Last  Name :" << c.l_name <<"\n";
         op<< "Telphone   :" << c.tele   <<"\n";
         op<< "Mobile     :" << c.mob   <<"\n";
         op<< "EMail ID   :" << c.email   <<"\n";
         op<< "Group      :" << c.loc   <<"\n";
         op<< "Location   :" << c.grp   <<"\n";
         op<< "Abilities  :" << c.abil   <<"\n";
         return op;
}


std::ostream& operator<<(std::ostream& op , Contact* c){
         op<< "First Name :" << c->f_name <<"\n";
         op<< "Last  Name :" << c->l_name <<"\n";
         op<< "Telphone   :" << c->tele   <<"\n";
         op<< "Mobile     :" << c->mob   <<"\n";
         op<< "EMail ID   :" << c->email   <<"\n";
         op<< "Group      :" << c->loc   <<"\n";
         op<< "Location   :" << c->grp   <<"\n";
         op<< "Abilities  :" << c->abil   <<"\n";
         return op;
}        
      
 

long Contact::get_mob(){
                   return this->tele;
                }
 
void Contact::set_mob(long num){
                   assert(num >0);
                   this->mob = num;
                }

 
string Contact::get_email(){
                   return this->email;
                }
 
void Contact::set_email(string e){
                    this->email = e;
                }


string Contact::get_loc(){
                   return this->loc;
                }
 
void Contact::set_loc(string ltion){
                   this->loc.assign(ltion);
                }

string Contact::get_grp(){
                   return this->grp;
               }

void  Contact::set_grp( string grp){
                  this->grp.assign(grp);
               }

char Contact::get_Abils(){
                   return this->abil;
               }

void Contact::set_Abils(char ab){
                    int num = ab-'0';
                    assert(num >0);
                    this->abil = ab;
               }




