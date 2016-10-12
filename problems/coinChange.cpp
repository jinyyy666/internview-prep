#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// my recursive solution of the coin change problem:
class Solution{
public:
  void coinChange(vector<int>& change, const vector<int>& measure, int val){
    if(val == 0)
      return;
    
    
    // traverse through the measure to find out the maximum measure that is less than val:
    int base = 0;
    int i = 0;
    for(; i < measure.size(); ++i)
      if(val >= measure[i])
	continue;
      else{
	base = measure[i-1];
	break;
      }
    
    int index = i-1;
    base = base == 0 ? measure.back() : base;
    change[index] += val/base;
    val = val % base;
    
    coinChange(change, measure, val);
  }
};

int main(int argc, char** argv){
  Solution S;
  if(argc != 1){
    cout<<"Please follow this input pattern: cat testcoinChange.txt | ./coinChange !"
	<<endl;
    return -1;
  
  }
  string line;
  string data;
  ifstream f("testcoinChange.txt");
  assert(f.is_open());
  while(getline(f,line)){
    istringstream iss(line);
    vector<int> measure;
    int val;
    iss>>val;
    assert(val >= 0);
    int base;
    while(iss>>base){
      assert(base > 0);
      measure.push_back(base);
    }
    assert(measure.size() != 0);
    vector<int> change(measure.size(), 0);
    S.coinChange(change, measure, val);
    cout<<"\nThe change for "<<val;
    
    int sum = 0;
    for(int i = 0; i < change.size(); ++i){
      if(change[i] != 0){
	cout<<" \n-> "<<change[i]<<" numbers of "<<measure[i];
	sum += change[i]*measure[i];
      }
    }
    assert(sum == val);
    cout<<endl;
  }
 
     
  return 0;

}
