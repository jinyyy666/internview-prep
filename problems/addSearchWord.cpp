#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class TrieNode{
public:
    bool isWord;
    TrieNode * children[26];
    TrieNode():isWord(false){
        memset(children, 0, sizeof(children));
    }
};
class WordDictionary {
private:
    TrieNode * root;
    void destroy(TrieNode * node){
        for(int i = 0; i < 26; ++i)
            if(node->children[i])   destroy(node->children[i]);
        delete node;
    }
public:
    WordDictionary(){
        root = new TrieNode();
    }
    ~WordDictionary(){
        destroy(root);
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * node = root;
        for(char c : word){
            if(!(node->children[c - 'a']))
                node->children[c - 'a'] = new TrieNode();
            node= node->children[c - 'a'];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, root, 0);
    }
    
    bool query(string word, TrieNode * node, int start){
        TrieNode * run = node;
        for(int i = start; i < word.length(); ++i){
            char c = word[i];
            if(run && c != '.'){
                // go to next
                run = run->children[c - 'a'];
            }
            else if(run && c == '.'){
                // try all possible, start 26
                TrieNode * tmp = run;
                for(int j = 0; j < 26; ++j){
                    run = tmp->children[j];
                    if(query(word, run, i+1))
                        return true;
                }
            }
            else break;
        }
        return run && run->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char ** argv){
  WordDictionary w;
  w.addWord("bad");
  w.addWord("mad");
  w.addWord("dad");
  
  cout<<w.search(".ad")<<endl;
}
