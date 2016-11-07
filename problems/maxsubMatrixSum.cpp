//Problem: Given a 2D array, find the maximum sum subarray in it

#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
  // function to find out the maximum subarray sum:
  int maximumSubarraySum(vector<int>& nums, int& start, int& end){
    // idea: keep track of two local variable, one for the maximum variable 
    if(nums.empty())  return 0;
    int max_ending_here = nums[0], max_so_far = nums[0], local_start = 0, local_end = 0;
    for(int i = 1; i < nums.size(); ++i){
      if(nums[i] > max_ending_here + nums[i])  local_start = i;
      max_ending_here = max(max_ending_here + nums[i], nums[i]);
      if(max_so_far < max_ending_here){
	start = local_start;
	end = i;
      }
      max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
  }
  
  int maximumSubmatrixSum(vector<vector<int> >& matrix, int& left, int& right, int& top, int& bottom){
    if(matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    // idea: One nested loop for i-j columns, can calculate the maxSum within the (i_th ~ j_th) column! 
    int maxSum = matrix[0][0];
    for(int i = 0; i < n; ++i){
      vector<int> tmp(m, 0);
      int begin = 0, end = 0;
      for(int j = i; j < n; ++j){
	
	for(int k = 0; k < m; ++k)  tmp[k] += matrix[k][j];
	
	int sum = maximumSubarraySum(tmp, begin, end);
	if(sum > maxSum){
	  maxSum = sum;
	  left = i, right = j;
	  top = begin, bottom = end;
	}
      }
    }
    return maxSum;
  }
};

int main(int argc, char ** argv){
  vector<vector<int> > test({{ -10, -2, -1, -4, -20},
	{-8, -3, -4, -2, -1}, {-3, -8, -10, -1, -3}, {-4,-1, 0, -7, -6}});
  Solution s;
  int start = 0, end = 0;
  for(int i = 0; i < test.size(); ++i){
    int sum = s.maximumSubarraySum(test[i], start, end);
    cout<<"Maximum subarry sum : "<<sum<<" start : "<<start<<" end : "<<end<<endl;
  }
  int left = 0, right = 0, top = 0, bottom = 0;
  cout<<"Maximum submatrix sum : "<<s.maximumSubmatrixSum(test, left, right, top, bottom)<<endl;
  cout<<"Range: left, right, top, bottom: "<<left<<"\t"<<right<<"\t"<<top<<"\t"<<bottom<<endl;
}
