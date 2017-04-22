#include<iostream>

#include"trie.h"
node::node()
{
	words = 0;
	prefixes = 0;
	for (int i = 0; i < 26; i++) {
		edges[i] = 0;
	}
}

node::~node()
{
	words = 0;
	prefixes = 0;
	for (int i = 0; i < 26; i++) {
		if (this->edges[i]) {
			this->edges[i]->~node();
		}
	}
	delete this; /* non safe */
}

trie::trie()
{
	root = new node();
	assert(root);
}

trie::~trie()
{
	if (this->root) {
		for (int i = 0; i < 26; i++) {
			if (this->root->edges[i]) {
				this->root->edges[i]->~node();
			}
		}
	}
}

void trie::add_word(std::string str)
{
	assert(this->root);
	this->add_word(this->root, str);
}

void trie::add_word(node *n, std::string str)
{
	assert(n);

	if (str[0] == '\0') {
		n->words++;
		return;
	} else {
		n->prefixes++;
		int index = str[0] - 'a';
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
		int index = str[0] - 'a';
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
		int index = str[0] - 'a';
		if (n->edges[index] == 0) {
			return n->prefixes;
		}
		str.erase(0,1);
		return count_prefixes(n->edges[index], str);
	}
}

int trie::find_word(std::string str)
{
	return find_word(this->root, str);
}

/*if abcd is added and abc is searched, then its not a valid case */
int trie::find_word( node *n, std::string str)
{
	if (str[0] =='\0') {
		if (n->words >0) {
			return 0;    /* Success */
		} else {
			return -1;
		}
	} else {
		int index = str[0]-'a';
		if (n->edges[index] == 0) {
			return -1;
		}
		str.erase(0,1);
		return find_word(n->edges[index],str);
	}
}
