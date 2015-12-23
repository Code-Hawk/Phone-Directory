#include<iostream>
#include"trie.h"
#include"assert.h"
#include<string>
using namespace std;
/* construtor*/
node::node()
{
	words = 0;
	prefixes = 0;
	for (int i=0; i<26; i++) {
		edges[i] = 0;
	}
	std::cout<<"Node constructed"<<std::endl;
}

/* Destructor */
node::~node()
{
	words = 0;
	prefixes = 0;
	for (int i=0; i<26; i++) {
		if (this->edges[i]!=0) {
			this->edges[i]->~node();
		}
	}
	std::cout<<"Node Destructed"<<std::endl;
	delete this; /* non safe */
}

trie::trie()
{
	root = new node();
	std::cout<<" Trie constructor " << std::endl;
	assert(root!=0);
}

trie::~trie()
{
	if (this->root !=0) {
		for (int i=0; i<26; i++) {
			if (this->root->edges[i]) {
				this->root->edges[i]->~node();
			}
		}
	}
}


void trie::add_word(std::string str)
{
	assert(this->root!=0);
	this->add_word(this->root,str);
}

/** should be the pointer of initial node ?? */
void trie::add_word(node *n, std::string str)
{
	assert(n!=0);

	if (str[0]=='\0') {
		n->words++;
		return;
	} else {
		n->prefixes++;
		int index = str[0]-'a';
		str.erase(0,1);
		if (n->edges[index] == 0) {
			n->edges[index] = new node();
		}
		add_word(n->edges[index],str);
	}
}

int trie::count_words(node *n, std::string str)
{

	if (str[0] == '\0') {
		return n->words;
	} else {
		int index = str[0]-'a';
		if (n->edges[index] == 0) {
			return 0;
		}
		str.erase(0,1);
		return count_words(n->edges[index],str);
	}
}

int trie::count_prefixes(node *n, std::string str)
{

	if (str[0] =='\0') {
		return 0;
	} else {
		int index = str[0]-'a';
		if (n->edges[index] == 0) {
			return n->prefixes;
		}
		str.erase(0,1);
		return count_prefixes(n->edges[index],str);
	}
}

int trie::find_word(std::string str)
{
	return find_word(this->root, str);
}

/*if yash is added and yas is searched, then its not a valid case */
int trie::find_word( node *n, std::string str)
{
	std::cout<<" String is "<< str<<endl;
	if (str[0] =='\0') {
		if (n->words >0) {
			return 0;    /* Success */
		} else {
			return -1;
		}
	} else {
		int index = str[0]-'a';
		std::cout<<"Index is : "<< index <<endl;
		if (n->edges[index] == 0) {
			std::cout<<"tree is cut "<< endl;
			return -1;
		}
		str.erase(0,1);
		std::cout<<" After erasing "<<str << endl;
		return find_word(n->edges[index],str);

	}
}



















