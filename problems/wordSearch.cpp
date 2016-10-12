#include <vector>
#include <utility>
#include <string>
#include <unordered_set>
using namespace std;


class TrieNode {
private:
    bool isEnd;
    int kChars;
    vector<TrieNode*>   links;
public:
    TrieNode() : isEnd(false), kChars(26), links(vector<TrieNode*>(kChars, NULL)){}
    TrieNode * getChar(char ch){    return links[ch - 'a'];}
    void putChar(char ch){    links[ch - 'a'] = new TrieNode();}
    void setWord(){ isEnd = true; }
    bool isWord(){ return isEnd; }
};

class Trie {
private:
    TrieNode * root;
    void destroy(TrieNode * node){
        if(!node)   return;
        for(char c = 'a'; c <= 'z'; ++c){
            TrieNode * tmp = node->getChar(c);
            if(tmp)
                destroy(tmp);
        }
        delete node;
    }
public:
    Trie(){ root = new TrieNode();}
    ~Trie(){ destroy(root);}
    void insert(string word) {
        TrieNode * node = root;
        for(auto c : word){
            // if the link does not exist, create it
            if(!node->getChar(c))
                node->putChar(c);
            node = node->getChar(c);
        }
        node->setWord();
    }
    TrieNode * find(string & s){
        TrieNode * node = root, * next;
        for(char c : s){
            next = node->getChar(c);
            if(!next)
                return NULL;
            node = next;
        }
        return node;
    }
    
    bool startWith(string prefix, bool & word){
        TrieNode * node = find(prefix);
        word = node && node->isWord();
        return node == NULL ? false : true;
    }
};

class Solution {
private:
    vector<pair<int, int> > dirs;
public:
    Solution(){
        dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ret;
	vector<string>	res;
        if(board.empty() || words.empty())  return res;
        // construct the Trie out of the words:
        Trie trie;
        for(string & word : words)  trie.insert(word);
        
        int m = board.size();
        int n = board[0].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                helper(ret,visited, i, j, trie, "", board);
            }
        }
	
	for(string str: ret)	res.push_back(str);
        return res;
    }
    void helper(unordered_set<string>& ret, vector<vector<bool> >& visited, int i, int j, Trie & trie, string word, vector<vector<char>>& board){
	if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())	return;
	if(visited[i][j])	return;
        bool isWord = false;
	word += board[i][j];
        if(!trie.startWith(word, isWord))   return;
        if(isWord){
            ret.insert(word);
        }
	visited[i][j] = true;
        for(pair<int, int> & d : dirs){
            int x = i + d.first, y = j + d.second;
            helper(ret, visited, x, y, trie, word, board);
            
        }
	visited[i][j] = false;
    }
};

int main(int argc, char ** argv){
	Solution solution;

	vector<vector<char> > board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	vector<string> words = {{"oath"},{"pea"},{"eat"},{"rain"}};
	vector<string> ret = solution.findWords(board, words);
	return 0;
}
