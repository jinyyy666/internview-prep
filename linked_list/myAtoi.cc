#include <iostream>
#include <cstdlib>

using namespace std;

class Solution{
public:
bool isNum(char c){
  return (c >= '0' && c <= '9') ? true : false;
}


int myAtoi(char * str){
  if(str == NULL)
    return 0;
  int sign = 1;
  int res = 0;
  int i = 0;
  if(str[i] == '-'){
    sign = -1;
    i++;
  }
  for(; str[i] != '\0'; ++i){
    char c = str[i];
    if(isNum(c) == false)
      return sign*res; // handle the specifical case;
    res = 10*res + str[i] - '0';
  }

  return sign*res;
}
};

int main(int argc, char** argv){
  Solution S;
  for(int i = 1; i < argc; ++i)
    cout<<argv[i]<<": "<<S.myAtoi(argv[i])<<"\t"<<atoi(argv[i])<<endl;
  return 0;

}
