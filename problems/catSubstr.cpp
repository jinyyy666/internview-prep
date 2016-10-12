#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>


using namespace std;

class Solution{
public:
vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty())  return res;
        int begin = 0, end = 0, counter = words.size();
        unordered_map<string, int> dict;
        for(string str : words) dict[str]++;
        int wl = words[0].length();
	unordered_map<string, int> tdict = dict;

        while(end + wl <= s.length()){
            string word = s.substr(end, wl);
            if(tdict.count(word) != 0 && tdict[word] > 0){ // find this word
                counter--; // modify the counter
                tdict[word]--;
                end += wl;
            }
            else{
		begin = end;
                counter = words.size();
		tdict = dict;
		if(tdict.count(word) == 0)
	                end++;
            }
            
            while(counter == 0){
                string w = s.substr(begin, wl);
                if(tdict.count(w) != 0 && tdict[w] == 0){
                    tdict[w]++;
                    counter++;
                    res.push_back(begin);
                    begin += wl;
                }
                else
                    begin++;
            }
                
        }
        return res;
    }
};

int main(int agrc, char ** argv){
	Solution S;
	vector<string> words = {"word", "good", "best", "good"};
	string s = "wordgoodgoodgoodbestword";
	vector<int> res = S.findSubstring(s, words);
	for(int i = 0; i < res.size(); ++i)
		cout<<res[i]<<endl;
}
