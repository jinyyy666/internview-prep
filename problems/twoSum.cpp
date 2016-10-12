#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
  // reverse int:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		unordered_map<int, int> hmap;
		for(int i = 0; i < nums.size(); ++i){
			if(hmap.find(nums[i]) == hmap.end()){
				hmap[target-nums[i]] = nums[i];
			}
			else{
				if(hmap[nums[i]] > nums[i]){
					ret.push_back(nums[i]);
					ret.push_back(hmap[nums[i]]);
				}
				else{
					ret.push_back(hmap[nums[i]]);
					ret.push_back(nums[i]);
				}
			}
		}
		return ret;
    	}	
};

int main(int argc, char** argv){
  Solution S;
  vector<int> nums;
  if(argc < 3){
	cout<<"./twoSum num1 num2 num3 target !!!"
	    <<endl;
	return -1;
  }
  for(int i = 1; i < argc-1; i++){
    nums.push_back(atoi(argv[i]));
  }
  vector<int> ret = S.twoSum(nums, atoi(argv[argc-1]));
  for(int i = 0; i < ret.size(); ++i)
	cout<<ret[i]<<endl;

  return 0;


}
