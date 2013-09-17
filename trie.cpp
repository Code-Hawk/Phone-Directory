#include"trie.h"
#include"assert.h"
using namespace std;
node::node()
{
    words = 0;
    prefixes = 0;
    for(int i=0;i<26;i++)
       { 
          edges[i] = 0;
       }
}

node::~node()
{    
     
        words = 0; 
        prefixes = 0;
        for (int i=0;i<26;i++){
             ~node();
             }
       
}

trie::trie(){
       root = new node();
       assert(root!=0);
}

trie::~trie(node *n){
         if(n!=0) {
           for( int i=0;i<26;i++)
              { 
                ~trie(node->edges[i]);
             }
 }
             
}         



/* should be the pointer of initial node ?? */
void trie::add_word(node *n, string *str){
       assert(n!=0);
       
       if(*str=='\0'){
          n->words++;
          return;
        }
       else{
             n->prefixes++;
             int index = *str-'a';        
             str++;
             if(n->edges[index] == 0){
                n->edges[index] = new node();
                }
              add_word(n->edges[index],str);
      }
}

int trie::count_words(node *n,string *str){
            
               if(*str == 0)
                 return 0;
             else{
                  int index = *str-'\0';
                  if( n->edges[index] == 0)
                      return 0;
                  str++;
                  return count_words(n->edges[index],str);
 }

}
  
int trie::count_prefixes(node *n, string *str){
              if(*str ==0)
                 return 0;
              else{
                   int index = *str-'\0';
                   if(n->edges[index] == 0)
                      return n->prefixes;
                   str++;
                   return count_prefixes(n->edges[index],str);  

       }
}
                
 











             
             





      
