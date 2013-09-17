#include<iostream>
#include"Contact.h"
#include"Verifier.h"
#include"Parser.h"
#include"core.h"
#include"trie.h"
using namespace std;

int main()
{  
   trie *db = new trie();
   db->add_word(string("yash"));
   db->add_word(string("yashavanth")); 
   std::cout<<" Inside Main" <<endl;
   std::cout<< "Finding word" << db->find_word(string("y"))<< endl;
   return 0;
}


