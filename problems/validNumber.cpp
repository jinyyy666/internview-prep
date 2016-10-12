#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution{
public:
    bool isNumber(string s) {
        bool hasNeg = false, hasDot = false, canHaveZero = false;
        if(s.empty())   return false;
        for(int i = 0; i < s.length(); ++i){
            if(i == 0 && s[i] == '-'){
                hasNeg = true;  continue;
            }
            if((i == 0 || i == 1 || i == 2) && s[i] == '.' && !hasDot){
                canHaveZero = true;
                hasDot = true;  continue;
            }
            if(i == 0 && s[i] <= '9' && s[i] > '0' ){
                canHaveZero = true;
                continue;
            }
            if(!canHaveZero && s[i] == '0' && i != 0) return false;
            //if(hasNeg && s[i] == '-')  return false;
            //if(hasDot && s[i] == '.')  return false;
            if(!(s[i]<= '9' && s[i] >= '0'))    return false;
        }
        return true;
    }
};

int main(int argc, char** argv){
    Solution s;
    vector<string> inputs({".05", "0.00500", "-0.5", "-5.0000", "00.00", "0001", "1-000"});
    for(string str : inputs){
       cout<<s.isNumber(str)<<endl;
    }
    return 0;

}
