#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

// my solution of finding the majority character (appears more than ) of a given string:
class Solution{
public:
  char stringMajority(string & str){
    if(str.empty()) return '\0';
    
    int cnt = 0;
    char target = '\0';

    // find out the majority by moore counting:
    for(size_t i = 0; i < str.length(); ++i){
      if(cnt == 0 || str[i] == target){
	cnt++;
	target = str[i];
      }
      else{
	cnt--;
      }
    }

    // double check if the number is the majority:
    cnt = 0;
    for(int i = 0; i < str.length(); ++i){
      if(str[i] == target)
	cnt++;
    }
    cout<<(int)('\0')<<endl;
    char a = 'a';
      cout<<++a<<endl;
    return cnt > str.length()/2 ? target : '\0';
  }  

  // return the char with the maximum occurance given the array:
  char stringMaximumOccurance(string& str){
    char count[256];
    memset(count, 0, sizeof(count));
    
    // count those characters:
    for(int i = 0; i < str.length(); ++i){
      count[str[i]]++;
    }
    
    int max = INT_MIN;
    size_t target;
    for(size_t i = 0; i < 255; ++i){
      if(count[i] > max){
	max = count[i];
	target = i;
      }
    }
    char t_c;
    memcpy(&t_c, (char *)&target, 1);  // one 
    return t_c;
    
    /*
    char t_c = '\0';
    char target = '\0';
    for(; t_c < UCHAR_MAX; t_c++){
      if(count[t_c] > max){
	max = count[t_c];
	target = t_c;
      }
    }
    return target;
    */
  }
};

int main(int argc, char** argv){
  Solution S;
  if(argc != 2){
    cout<<"Please follow this input pattern: ./stringMajority [string]  !"
	<<endl;
    return -1;
  
  }
  
  string str(argv[1]);
  char ret = S.stringMajority(str);
  if(ret == '\0')
    cout<<"You input string is empty?? If not then there is no majority for the given string!"<<endl;
  else
    cout<<"The majority of the string is "<<ret<<endl;

  ret = S.stringMaximumOccurance(str);
  if(ret == '\0')
    cout<<"You input string is empty??"<<endl;
  else
    cout<<"The char with the maximum occurance in the string is "<<ret<<endl;
  
  return 0;

}
