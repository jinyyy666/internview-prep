#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

class Solution{
public:
bool isNum(char c){
  return (c >= '0' && c <= '9') ? true : false;
}


int minDist(string & str, char* c1, char* c2){
  int dist = INT_MAX;
  int loc_1 = -1, loc_2 = -1;
  for(int i = 0; i < str.length(); ++i){
    if(loc_1 == -1 && loc_2 == -1){
      loc_1 = str[i] == *c1 ? i : -1;
      loc_2 = str[i] == *c2 ? i : -1;
    }
    else if(loc_1 == -1){
      if(str[i] == *c1){
	loc_1 = i;
	dist = min(loc_1 - loc_2, dist);
	loc_2 = -1;
      }
    }
    else if(loc_2 == -1){
      if(str[i] == *c2){
	loc_2 = i;
	dist = min(loc_2 - loc_1, dist);
	loc_1 = -1;
      }
    }
    else
      continue;
  }

  return (dist == INT_MAX) ? -1 : dist;
}

};

int main(int argc, char** argv){
  Solution S;
  for(int i = 1; i < argc; i += 3){
    string str(argv[i]);
    cout<<argv[i]<<": "<<S.minDist(str, argv[i+1], argv[i+2])<<endl;
  }
  return 0;


}
