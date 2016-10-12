#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
class ValidWordAbbr {
private:
    unordered_map<string, int> table;
    unordered_set<string> candidates;
    string abbreviation(const string & str){
        string ret;
        int n = str.length();
        if(n > 2){
            ret = str[0] + to_string(n-2) + str[n-1];
        }
        return ret;
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        string abbrev;
        for(auto & str: dictionary){
            abbrev = abbreviation(str);
            if(!abbrev.empty()){
                // increasement the table iff. for the new word
                if(candidates.find(str) == candidates.end())    table[abbrev]++;
            }
            if(str.length() > 2)  candidates.insert(str); 
        }
    }
 
    bool isUnique(string word) {
        string a = abbreviation(word);
        if(candidates.find(word) != candidates.end()){ // same word appears in the dict
            return table[a] == 1;
        }else{
            return table.find(a) == table.end();
        }
    }
};
 
 
// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
 
int main(int argc, char ** argv){
    vector<string>  dictionary(1,  "hello");
    ValidWordAbbr vwa(dictionary);
    cout<<vwa.isUnique("hello")<<endl;
}
