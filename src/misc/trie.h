#ifndef _TRIE_H
#define _TRIE_H
#include<string>

class node
{
	friend class trie;
public:
	node();
	~node();
private:
	int words;
	int prefixes;
	node *edges[26];
};


class trie
{
public:
	trie();
	~trie();

	void add_word(std::string str);
	void add_word(node *n, std::string str);
	int  count_prefixes(node *n, std::string str);
	int  count_words(node *n, std::string str);
	int  find_word(std::string str);
	int  find_word(node *n, std::string str);
	void initialise();
private:
	node *root;
};

#endif
