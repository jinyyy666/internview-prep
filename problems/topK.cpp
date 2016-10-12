#include <vector>
#include <unordered_map>
#include <iostream>
#include <assert.h>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Idea: hash-table with bucket sort:
        unordered_map<int, int> hash;
        int max_f = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = 0;
            }
            else{
                ++hash[nums[i]];
                max_f = max(hash[nums[i]], max_f);
            }
        }
        
        assert(max_f >= 0);
        vector<vector<int> > res(max_f+1, vector<int>());
        vector<int> ret;
        
        // bucket sort:
        for(auto it = hash.begin(); it != hash.end(); ++it){
            int freq = it->second;   
	    cout<<freq<<"\t"<<res.size()<<endl;
            res[freq].push_back(it->first);
        }
        
        int cnt = 0;
        for(int i = res.size() - 1; i >= 0 && cnt < k; --i){
            for(int j = 0; j < res[i].size() && cnt < k; ++j){
                ret.push_back(res[i][j]);
                ++cnt;
            }
        }
        
        return ret;
    }
};

int main(int argc, char ** argv){
	Solution S;
	vector<int> input = {1};
	vector<int> ret = S.topKFrequent(input, 1);
	return 0;
}
