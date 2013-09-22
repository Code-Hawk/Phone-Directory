#include "Core.h"
using namespace std;

int Core::instance = 0; /* Initialise static member for singleton */

/* Constructor */
Core::Core(const string& filepath){
                    
                  psr = new Parser(filepath);
                  vfy = new Verifier();
                  contacts_db = new List();
                  init();
}
/* Destructor - deletes other objects */
Core::~Core(){
              cout <<" Core Destructor called " << endl;   
              Core::instance--;
              delete this->psr;
              delete this->vfy;
              delete this->contacts_db;
              delete this->raw_db; /* TODO */
        }


int Core::interface(int opt){
 
  switch(opt){
   case 0:
          return this->init();
           
   case 1: 
            this->reinit();   
            return 0;
   case 3: 
             return  this->add_contact();
   case 4:
            //if(arg != NULL){
             // string *name = (string *)arg;
              return this->del_contact();
             // }
             //else return -1;  
   case 2: 
             this->display_all();
             return 0;
   case 5:
             this->sort_contacts();
             return 0;
   case 6:
              return this->search_contact();
              
   case -1:
             return this->stop();
     
   case 7:
             cout <<"Number of Contacts in Database are :" << this->get_no_contacts() <<endl;
       
     default:
           std::cout<< "Not a valid operation"<<std::endl;
           return -1;
       
}
}

Core *Core::Core_get_instance(string file){

                  if(Core::instance == 0 && (!file.empty())){
                    Core::instance++;
                      return new Core(file);
                   }
                  else{
                  std::cout<<"Its a singleton "<< std::endl;
                     return NULL;
                  }
}


int Core::init(){
        
         /* 
         * 1. Executed at the startup only.
         *  2. All the variables are set to 0.
         */
          
        cout << " Initialising the databases" << endl;  
        this->no_contacts = this->psr->get_no_lines();
    
        if(this->no_contacts < 1)
            {
              std::cout<< "Empty file "<< std::endl;
              return -1;
            } 
       
       this->raw_db = new std::string[this->no_contacts];
       assert(this->raw_db !=0); 
       std::cout<<" No of lines are " << this->no_contacts <<std::endl;
       this->psr->read_all(this->raw_db);
       string *temp = this->raw_db;
       std::vector<string> *tokens = new  std::vector<string>;

       for(int i=0; i<this->no_contacts; i++){

             if(!this->vfy->verify_entry(*temp, tokens)){
             std::cout<<" Verification failed for line :" <<i <<std::endl;
             *temp++;
             tokens->clear();
             continue;
           }
           
           if(tokens->size()){
            Contact *to_add = new Contact(tokens);
            this->contacts_db->add(to_add);
           }
          tokens->clear(); 
          temp++;
          
          }
      delete tokens;
      std::cout<<" Successfully initialised "<< std::endl;
      return 0;
}

int Core::get_no_contacts(){
         
         if(this->contacts_db !=0)
            return this->contacts_db->size();
         else 
           return 0;
}


void Core::display_all(){
             std::cout<<"Showing all available contacts"<< std::endl;
             this->contacts_db->show();
}


int Core::add_contact(){

         string read;
         vector<string> *toAdd = new vector<string>;

         Boolean ret=FALSE;
         while(ret!=TRUE){
         cout << " Enter the First name: ";
         cin >> read;
         ret = this->vfy->name_vfy(read);
         if(ret == FALSE)
            cout << "Invalid First Name" << endl;
         } 
         toAdd->push_back(read);    
      
         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the Last name: ";
         cin >> read;
         ret = this->vfy->name_vfy(read);
         if(ret == FALSE)
            cout << "Invalid Last Name" << endl;
         }
         toAdd->push_back(read);
     
         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the Telephone Number: ";
         cin >> read;
         ret = this->vfy->num_vfy(read);
         if(ret == FALSE)
            cout << "Invalid Telephone Number" << endl;
         }
         toAdd->push_back(read); 
          
         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the Mobile Number: ";
         cin >> read;
         ret = this->vfy->num_vfy(read);
         if(ret == FALSE)
            cout << "Invalid Mobile Number" << endl;
         }
         toAdd->push_back(read);

         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the Email id : ";
         cin >> read;
         ret = this->vfy->email_vfy(read);
         if(ret == FALSE)
            cout << "Invalid Email id" << endl;
         }
         toAdd->push_back(read);
 
         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the Location: ";
         cin >> read;
         ret = this->vfy->loc_vfy(read);
         if(ret == FALSE)
            cout << "Invalid Location" << endl;
         }
         toAdd->push_back(read);  

         ret = FALSE;
         while(ret!=TRUE){
         cout << " Enter the group: ";
         cin >> read;
         ret = this->vfy->loc_vfy(read);
         if(ret == FALSE)
            cout << "Invalid group" << endl;
         }
         toAdd->push_back(read);

         toAdd->push_back("0");
           
         Contact *con = new Contact(toAdd);
         this->contacts_db->add(con);
         cout << "Added a new Contact" <<endl;
         delete(toAdd);
         return 0;
}

/*Delete a contact based on first name only - May be 
 * enhance it for taking multiple arguements or
 * other fields.
 */
int Core::del_contact(){
         string read;
         cout << " Enter the First name: ";
         cin >> read;
         cout<< " Delete called for name: " << read ;
         this->contacts_db->del(read);
         return 0;
}

/* TODO implement sorting based on user input */
void Core::sort_contacts(){
      std::cout<<" Sort_contacts called"<< std::endl;
}

int Core::search_contact(){
    
    Boolean ret=FALSE;
    string read;
    
   /* not called untill a valid name is given */
    while(ret!=TRUE){
          cout << " Enter the Contact's First name to search: ";
          cin >> read;
          ret = this->vfy->name_vfy(read);
          if(ret == FALSE)
             cout << "Invalid First Name" << endl;
         }

    Contact *c = this->contacts_db->search(read);
    if(c != NULL)
       {
          std::cout<<" FOUND : " << c->get_f_name() <<endl; 
          std::cout<<" First name:" << c->get_f_name() << "  Last name: " << c->get_l_name() << "  Tel Num:" << c->get_tele() << "  Mob Num:" << c->get_mob() 
          << "\n" << " Email id:" << c->get_email() << "    Location:" << c->get_loc() << "   Group:" << c->get_grp() << "   Abilities:" << c->get_Abils() <<endl;
       }
    else{
        std::cout << read << " NOT FOUND " << endl;
          }
    return 0;
}

int Core::stop(){
    std::cout<<" Stop is called: Application ending "<<std::endl;
    return -1;

}

int edit_contact(string *name){

     std::cout<<" Contact edit has been called" << std::endl;
     return 0;
 }

/* Reinitialse the database */
int Core::reinit(){

        /* Don't clear the present database contents
         * untill the new database is setup
         */
 
        int n = this->psr->get_no_lines(); 
        if(n < 1)
            {
              std::cout<< "Empty file - Database Reinitialization failed"<< std::endl;
              return -1;
            }

        this->no_contacts = n;
        this->contacts_db->clr(); /*remove all the elements from list */
       std::cout<< "raw db pointer "<< this->raw_db <<endl; 
      // delete(this->raw_db); 
       cout << "Core::reinit() -- deleted raw db " << endl; 
       this->raw_db = new std::string[this->no_contacts];
       assert(this->raw_db !=0); 
       std::cout<<" No of lines are " << this->no_contacts <<std::endl;
       this->psr->read_all(this->raw_db);
       string *temp= this->raw_db;
       std::vector<string> *tokens = new  std::vector<string>;
       for(int i=0; i<this->no_contacts; i++)
           {
             if(!this->vfy->verify_entry(*temp, tokens)){
             std::cout<<" Verification failed for line :" <<i <<std::endl;
             *temp++;
             tokens->clear();
             continue;
           }
           
           if(tokens->size()){
            Contact *to_add = new Contact(tokens);
            this->contacts_db->add(to_add);
           }
          tokens->clear(); 
          temp++;
          
          }
      delete tokens;
   return 0;
 } 
    
       






        
          
