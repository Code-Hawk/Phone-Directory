#ifndef _TRIE_H
#define _TRIE_H

using namespace std;
 
class node{
          friend class trie;
          public:
                -node();  
                ~node(node *n); 
          private:
                  int words;
                  int prefixes;
                  node *edges[26];
                  node();
};


class trie{  
            public:
                    trie();
                   -trie();
                   ~trie(node *n);
                    void add_word(node * n, std::string *str);
                    int count_prefixes( node *n,std::string *str);
                    int count_words(node *n,std::string *str);
                    void initialise();
           private:
                   node *root;
  };
      
#endif             
