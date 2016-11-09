#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string copy(int k, string cur){
        string ret;
        if(k == 0)  return cur;
        for(int i = 0; i < k && !cur.empty(); ++i)  ret += cur;
        return ret;
    }
    string decodeString(string s) {
        // idea: Use stack, keep track of a current string, and the k
        // once encounter '[', push to stack the k and current string, start a new <k, string> pair
        // once encounter ']' pop up , merge the string to current string
        stack<pair<int, string> > st;
        int k = 0;
        string cur = "";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                k = 10*k + s[i] - '0';
            }
            else if(s[i] == '['){ // push to stack:
                st.push(make_pair(k, cur));
                k = 0;
                cur = "";
            }
            else if(s[i] == ']'){ // pop out of stack:
                string tmp = copy(k, cur); // copy cur k times
                auto p = st.top(); st.pop();
                cur = p.second + copy(p.first, tmp); // for the resulted one k times
                k = 0;
            }
            else{
                cur.push_back(s[i]);
            }
        }
        return cur;
    } 
};

int main(int argc, char ** argv){
  vector<string> test({"3[a2[c]]", "3[a2[3[c]]]"});
  Solution s;
  for(int i = 0;i < test.size(); ++i){
    cout<<test[i]<<"---->"<<s.decodeString(test[i])<<endl;
  }
  return 0;
}
