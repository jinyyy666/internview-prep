/*********************************************************************************
 * Problem: longest arithmetic progression
 * Given a set of numbers. find the Length of the Longest Arithmetic Progression
 * Examples:
 * Input: {1, 7, 10, 15, 27, 29}
 * Output: 3  
 * The longest arithmetic progression is {1, 15, 29}
 *
 * Input: {5, 10, 15, 20, 25, 30}
 * Output: 6
 * The whole set is in AP!
 *********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution{
public:
  int longestArithmeticProgression(vector<int>& nums){
    // the naive approach would be O(n^3) --> for every pair of points, you can use it as the first and second
    // element of the seq, and check the rest of n-2 element to see if anymore number is in the sequence.
    // idea: dp  --> O(n^2) dp[n][n] --> dp[i][k] the longest seq start from i and end in j
    // fix the ptr for the middle point j, extend it from two side 
    // <--i  j  k-->
    // if nums[i] + nums[k] > 2*nums[j] (i--) else if nums[i] + nums[k] < 2*nums[j] (k++)
    // if nums[i] + nums[k] == 2*num[j], that means you can extend the seq[j][k] to seq[i][k]!
    // that is dp[i][j] = dp[j][k] + 1
    // the last column of the table is 2, you fill the table from the bottom right to top left
    // keep track of the max, and return it!
    if(nums.size() <= 2)  return nums.size();
    int n = nums.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)  dp[i][n-1] = 2;

    // fix the middle point:
    int ret = 2;
    for(int j = n-2; j >= 1; --j){
      int i = j-1, k = j+1;
      while(i>= 0 && k < n){
	
	int sum = nums[i] + nums[k];
	if(sum < 2*nums[j])
	  k++;
	else if(sum > 2*nums[j]){
	  dp[i][j] = 2; // at least 2, initialize it here before changing the i
	  i--;
	}
	else{
	  dp[i][j] = dp[j][k] + 1;
	  ret = max(ret, dp[i][j]);
	  i--, k++;
	}
      }
      
      // handle the cases if the k is larger than n-1 but i has not reach the end
      while(i >= 0){
	dp[i][j] = 2;
	i--;
      }
    }
    return ret;
  }
};

int main(int argc, char ** argv){
  Solution s;
  vector<vector<int> > test({{1, 7, 10, 15, 27, 29}, {5, 10, 15, 20, 25, 30}, {1, 7, 10, 13, 14, 19}, {2, 4, 6, 8, 10, 12}});
  
  for(auto& v : test)
    cout<<s.longestArithmeticProgression(v)<<endl;

  return 0;
}
