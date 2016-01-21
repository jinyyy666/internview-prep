#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

// my solution of check the balance of the string:
class Solution{
public:
  bool checkBracketsBalance(string & str){
    if(str.empty())  return true;
    // first step: check the total number of open and close brackets
    int open = 0;  // two counters to keep track of the number of brackets
    int close = 0;
    
    for(int i = 0; i <str.length(); ++i){
      if(str[i] == '(')
	open++;
      if(str[i] == ')')
	close++;
    }
    if(open != close)
      return false;

    // second step: further check if the total number is matched:
    int start = 0, end = str.length()-1;
    bool right = true, left = true;
    for(; start < str.length(); start++){
      if(str[start] == '('){
	right = true; // if the string begins with open brackets
	break;
      }
      else if(str[start] == ')'){
	right = false;
	break;
      }
      else
	continue;
    }
    if(!right)  return false;

    for(; end >= 0; end--){
      if(str[end] == ')'){
	left = true; // if the string ends with close brackets
	break;
      }
      else if(str[end] == '('){
	left = false;
	break;
      }
      else
	continue;
    }
    if(!left)  return false;
    else  return true;
    
  }
};

int main(int argc, char** argv){
  Solution S;
  if(argc != 1){
    cout<<"Please follow this input pattern: cat testcheckBracket | ./checkBracketsBalance !"
	<<endl;
    return -1;
  
  }
  string str;
  while(cin>>str){
  
    bool ret = S.checkBracketsBalance(str);
    cout<<"The input string: "<<str;
    if(ret == true)
      cout<<" is bracket-balanced!!"<<endl;
    else
      cout<<" is not bracket-balanced!!!"<<endl;
  }
  
  return 0;

}
