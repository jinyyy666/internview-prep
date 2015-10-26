#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

class Solution{
public:
void myRev(string & str){
  unsigned int start = 0;
  unsigned int end = str.length()-1;
  while(end > start){
    // swap:
    str[start] ^= str[end];
    str[end]   ^= str[start];
    str[start] ^= str[end];
    end--;
    start++;
  }
}

  // reverse int:
int reverse(int x) {
        bool neg = x < 0;
        if(neg && x != INT_MIN) x = -1*x;
	if(x == INT_MIN)
	  return 0;

        long int ret = 0;
        while(x != 0){
	  cout<<x%10<<"\t"<<ret<<endl;
            ret = ret*10 + x%10;
            x /= 10;
        }
        
	if(ret > INT_MAX)
	  return 0;
	else
	  return neg ? -1*ret : ret;
    }

};

int main(int argc, char** argv){
  Solution S;
  for(int i = 0; i < argc; i++){
    string str(argv[i]);
    S.myRev(str);
    cout<<argv[i]<<"--> "<<str<<endl;
  }
  return 0;


}
