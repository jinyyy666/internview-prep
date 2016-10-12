#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> map(26, 0);
        if(s.empty())   return true;
        if(t.empty())   return false;
        for(char c : s) map[c-'a']++;
        bool isSub = true;
        bool allZero = false;
        int begin = 0; // begin ptr for searching in s
        for(char c : t){
            if(map[c-'a'] != 0){
                    if(s[begin] == c){
                        begin = i+1;
                        map[c-'a']--;
                        break;
                    }
                
                allZero = true;
                for(int i = 0; i < 26; ++i){
                    if(map[i])  allZero =false;
                }
            }
            //if(begin == s.length() && allZero == false){
               // return false;
            //}
        }
        return allZero;
    }
};

int main(int argc, char ** argv){
  Solution sol;
  string s = "leeetcode";
  string t = "leeeetcode";
  bool result = sol.isSubsequence(s, t);
  cout<<result<<endl;
  return 0;
}
