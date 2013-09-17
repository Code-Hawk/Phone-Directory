#include "Contact.h"
 
Contact::Contact(){
     
        First_name="";
        Last_name="";
        std::fill_n(Telephone,10,0);
        std::fill_n(Mobile,10,0);
        Email_id="";
        Location="";
        Group="";
        std::fill_n(Abilities,5,NONE);
}

 
    Contact::Contact(string First_name, string Last_name, int **Telephone, int **Mobile,string email, string Location, string Group, CAPABILITIES **Abilities){
       First_name = First_name;
       Last_name = Last_name;
       Telephone = *Telephone;
       Mobile = *Mobile;
       email = email;
       Location = Location;
       Group = Group;
       Abilities = *Abilities;
}


       

