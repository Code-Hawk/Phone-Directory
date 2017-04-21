#include "Core.h"
#include "../globals.h"

#define FIELDS 7
using namespace std;

int Core::instance = 0;
extern Logger *DEBUGGER;

Core::Core(const string &filepath)
{
	psr = new Parser(filepath);
	vfy = new Verifier();
	contacts_db = new List();
	init();
}

Core::~Core()
{
	DEBUGGER->log_debug(" Core Destructor");
	Core::instance--;
	delete this->psr;
	delete this->vfy;
	delete this->contacts_db;
	delete[] this->raw_db;
}

int Core::interface(int opt)
{
	switch (opt) {

		case 0:
			return this->init();

		case 1:
			this->reinit();
			return 0;

		case 2:
			this->display_all();
			return 0;

		case 3:
			return this->add_contact();

		case 4:
			return this->del_contact();

		case 5:
			this->sort_contacts();
			return 0;

		case 6:
			return this->search_contact();

		case 7:
			cout <<"Number of Contacts in Database are :" << this->get_no_contacts() <<endl;
			return 0;

		case -1:
			return this->stop();

		default:
			std::cout<< "Not a valid operation"<<std::endl;
			return -1;
	}
}

Core *Core::Core_get_instance(string file)
{
	if (Core::instance == 0 && (!file.empty())) {
		Core::instance++;
		return new Core(file);
	} else {
		std::cout<<"Its a singleton "<< std::endl;
		return NULL;
	}
}

int Core::init()
{
	DEBUGGER->log_debug("Initialising the databases");
	this->no_contacts = this->psr->get_no_lines();

	if (this->no_contacts < 1) {
		DEBUGGER->log_debug("Empty file ");
		return -1;
	}

	this->raw_db = new std::string[this->no_contacts];
	assert(this->raw_db);
	this->psr->read_all(this->raw_db);
	string *temp = this->raw_db;
	std::vector<string> *tokens = new  std::vector<string>;

	for (int i = 0; i < this->no_contacts; i++) {
		if (!this->vfy->verify_entry(*temp, tokens)) {
			temp++;
			tokens->clear();
			continue;
		}

		if (tokens->size()) {
			Contact *to_add = new Contact(tokens);
			this->contacts_db->add(to_add);
		}
		tokens->clear();
		temp++;
	}

	delete tokens;
	DEBUGGER->log_debug("Successfully initialised ");
	return 0;
}

int Core::get_no_contacts()
{
	if (this->contacts_db !=0) {
		return this->contacts_db->size();
	} else {
		return 0;
	}
}

void Core::display_all()
{
	DEBUGGER->log_debug("Showing all available contacts");
	this->contacts_db->show();
}

int Core::add_contact()
{
	string read;
	vector<string> *toAdd = new vector<string>;

	Boolean ret = FALSE;
	while (ret != TRUE) {
		cout << "Enter the First name: ";
		cin >> read;
		ret = this->vfy->name_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid First Name" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the Last name: ";
		cin >> read;
		ret = this->vfy->name_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid Last Name" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the Telephone Number: ";
		cin >> read;
		ret = this->vfy->num_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid Telephone Number" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the Mobile Number: ";
		cin >> read;
		ret = this->vfy->num_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid Mobile Number" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the Email id : ";
		cin >> read;
		ret = this->vfy->email_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid Email id" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the Location: ";
		cin >> read;
		ret = this->vfy->loc_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid Location" << endl;
		}
	}
	toAdd->push_back(read);

	ret = FALSE;
	while (ret!=TRUE) {
		cout << "Enter the group: ";
		cin >> read;
		ret = this->vfy->loc_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid group" << endl;
		}
	}
	toAdd->push_back(read);
	toAdd->push_back("0");

	Contact *con = new Contact(toAdd);
	this->contacts_db->add(con);
	cout << "Added a new Contact" <<endl;
	delete(toAdd);
	return 0;
}

int Core::del_contact()
{
	string read;
	cout << "Enter the First name: ";
	cin >> read;
	this->contacts_db->del(read);
	return 0;
}

void Core::sort_contacts()
{
	this->contacts_db->sort();
	std::cout<<"Contacts sorting success-- > Enter option 2 to view  " << std::endl;
}

int Core::search_contact()
{
	Boolean ret=FALSE;
	string read;
	/* TODO - may be searching based on other fields ??? */
	/* not called untill a valid name is given */
	while (ret!=TRUE) {
		cout << "Enter the Contact's First name to search: ";
		cin >> read;
		ret = this->vfy->name_vfy(read);
		if (ret == FALSE) {
			cout << "Invalid First Name" << endl;
		}
	}

	Contact *c = this->contacts_db->search(read);
	if (c != NULL) {
		std::cout <<"Contact has been FOUND"<< std::endl;
		std::cout <<c ;
		std::cout << "Want to edit ? Yes / No " << std::endl;
		string repeat;
		while (1) {
			std::cin >> repeat;
			if ((repeat.compare("Yes") != 0 ) && (repeat.compare("No")!=0)) {
				cout << "Invalid input.  Try again: ";
			} else {
				break;
			}
		}

		if (repeat.compare("Yes") == 0) {
			return this->edit_contact(c);
		} else {
			return 0;
		}
	} else {
		std::cout << read << " Contact with this name not  FOUND " << endl;
	}
	return 0;
}

int Core::stop()
{
	DEBUGGER->log_debug(" Stop is called: Application ending ");
	return -1;
}

int Core::reinit()
{
	int n = this->psr->get_no_lines();
	if (n < 1) {
		DEBUGGER->log_debug("Empty file - Database Reinitialization failed");
		return -1;
	}

	this->no_contacts = n;
	this->contacts_db->clr();

	this->raw_db = new std::string[this->no_contacts];
	assert(this->raw_db !=0);
	this->psr->read_all(this->raw_db);

	string *temp = this->raw_db;
	std::vector<string> *tokens = new std::vector<string>;

	for (int i=0; i < this->no_contacts; i++) {
		if (!this->vfy->verify_entry(*temp, tokens)) {
			temp++;
			tokens->clear();
			continue;
		}

		if (tokens->size()) {
			Contact *to_add = new Contact(tokens);
			this->contacts_db->add(to_add);
		}
		tokens->clear();
		temp++;
	}

	delete tokens;
	return 0;
}

int Core::edit_contact(Contact *c)
{
	int option;
	bool fields[FIELDS];
	bool edited = false;

	for (int i=0; i < FIELDS ; i++) {
		fields[i] = false;
	}
	string newvalue[8];

repeat:
	if (edited == false) {
		std::cout <<
			" Select the field to edit :		\
			\n\t First_Name ==> 1				\
			\n\t Last Name ==> 2 				\
			\n\t Telephone ==> 3 				\
			\n\t Mobile ==> 4					\
			\n\t Email ==> 5					\
			\n\t Location ==> 6					\
			\n\t Group ==> 7					\
			\n\t Quit ==> 8"					\
			<< std::endl;
	} else {
		std::cout << 
			" Select the field to edit :		\
			\n\t SAVE ==> 0						\
			\n\t First_Name ==> 1 				\
			\n\t  Last Name ==> 2 				\
			\n\t Telephone ==> 3 				\
			\n\t Mobile ==> 4					\
			\n\t Email ==> 5					\
			\n\t Location ==> 6					\
			\n\t Group ==> 7					\
			\n\t Quit ==> 8"					\
			<< std::endl;
	}

	while (!(cin >> option)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Field is selected, Try again: ";
	}
	if (option < 0 || option > 8) {
		std::cout << " Invalid field selected";
		goto repeat;
	} else {
		Boolean ret = FALSE;
		string read;

		switch (option) {
			case 1: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the First name: ";
					cin >> read;
					ret = this->vfy->name_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid First Name" << endl;
					}
				}
				newvalue[0] = read ;
				fields[0] = true;
				edited = true;
				break;
			}

			case 2: {
				Boolean ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the Last name: ";
					cin >> read;
					ret = this->vfy->name_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid Last Name" << endl;
					}
				}
				newvalue[1] = read;
				fields[1] = true;
				edited = true;
				break;
			}

			case 3: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the Telephone Number: ";
					cin >> read;
					ret = this->vfy->num_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid Telephone Number" << endl;
					}
				}
				newvalue[2] = read;
				fields[2] = true;
				edited = true;
				break;
			}

			case 4: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the Mobile Number: ";
					cin >> read;
					ret = this->vfy->num_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid Mobile Number" << endl;
					}
				}
				newvalue[3] = read;
				fields[3] = true;
				edited = true;
				break;
			}

			case 5: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the Email id : ";
					cin >> read;
					ret = this->vfy->email_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid Email id" << endl;
					}
				}
				newvalue[4] = read;
				fields[4] = true;
				edited = true;
				break;
			}

			case 6: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the Location: ";
					cin >> read;
					ret = this->vfy->loc_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid Location" << endl;
					}
				}
				newvalue[5] = read;
				fields[5] = true;
				edited = true;
				break;
			}

			case 7: {
				ret = FALSE;
				while (ret!=TRUE) {
					cout << " Enter the group: ";
					cin >> read;
					ret = this->vfy->loc_vfy(read);
					if (ret == FALSE) {
						cout << "Invalid group" << endl;
					}
				}
				newvalue[6] = read;
				fields[6] = true;
				edited = true;
				break;
			}

			case 0:
				/* Here comes the tricky part -- since C++ does not support reflection ...
				   Bad idea to add each field manually */
				if (edited == false) {
					std::cout<<" No fields has been edited to save " << std::endl;
					return 0;
				} else {
					if (fields[0] ==true) {
						c->set_f_name(newvalue[0]);
					}

					if (fields[1] ==true) {
						c->set_l_name(newvalue[1]);
					}

					if (fields[2] ==true) {
						std::cout <<"Telephone number edited " << std::endl;
						long num = std::atol(newvalue[2].c_str());
						c->set_tele(num);
					}
					if (fields[3] ==true) {
						long num = std::atol(newvalue[3].c_str());
						c->set_mob(num);
					}

					if (fields[4] ==true) {
						c->set_email(newvalue[4]);
					}

					if (fields[5] ==true) {
						c->set_loc(newvalue[5]);
					}

					if (fields[6] ==true) {
						c->set_grp(newvalue[6]);
					}
					cout << c;
					return 1;
				}
			default: {
				std::cout<<" Invalid field selected" <<std::endl;
				edited = false;
			}
		}
		goto repeat;
	}
}
