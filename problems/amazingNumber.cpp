/***************************************************************
 * The problem of amazing number:
 * Define amazing number as: its value is less than or equal to its index. 
 * Given a circular array, find the starting position, 
 * such that the total number of amazing numbers in the array is maximized.
 * Example 1: 0, 1, 2, 3
 * Ouptut: 0.    
 * When starting point at position 0, all the elements in the array are equal to its index. So all the numbers are amazing number.
 * Example 2: 1, 0 , 0. From 1point 3acres bbs
 * Output: 1.    
 * When starting point at position 1, the array becomes 0, 0, 1. 
 * All the elements are amazing number. 
 * If there are multiple positions, return the smallest one.
 ***************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  int amazingNumber(vector<int>& nums){
    // For each num in the array, there exists a range where we can shift the head into that 
    // range to make the current number to be amazing, for example:
    //       0 1 2 3 4 5 6
    // nums: 0 1 2 3 5 4 6
    //               i
    // inds: 2 3 4 5 6 0 1 
    // inds: 1 2 3 4 5 6 0
    // arr : 0 0 0 0 0 1 0  1->means the start of the range, -1->means the end:
    // possible range for changing 5: [5,6]
    // idea: keep an array to indicate that the start/end of the range
    // scan the array and find out the max number of overlapped intervals! (kind of like meeting room!)
    if(nums.empty())  return 0;
    int n = nums.size();
    vector<int> shift(n, 0);
    for(int i = 0; i < n; ++i){
      if(nums[i] >= n || nums[i] <= 0)  continue; // these two cases will not affect the result
      
      if(nums[i] > i){
	// need to shift, first let make i+1 as the new start, then the current number will have index of n-1
	shift[i+1]++;
	// determine the end of the range, if nums[i] == i+1, end of the range is in index = n, note that the end is a open range! then we do not need to keep track of 
	// also note that in this case the end range cannot be on the left of the current number!
	if(nums[i] > i+1)  shift[n-1 -(nums[i] - i+1) + 1]--;
      }
      else{
	// two ranges exists in this case! one starts from 0 to i-nums[i]+1, the other starts from i+1
	shift[0]++;
	shift[i-nums[i]+1]--;
	if(i+1 != n) shift[i+1]++;
      }
    }
    //scan from the array and finding the max overlapped intervals and keep track of the index:
    int index = 0, maxO = 0, sum = 0;
    for(int i = 0; i < shift.size(); ++i){
      sum += shift[i];
      if(sum > maxO){
	sum = maxO;
	index = i;
      }
    }
    return index;
  }
};


int main(int argc, char ** argv){
  vector<vector<int> > test(vector<vector<int> >({{0,1,2,3},{1,0,0},{0,1,2,5,4,7,6},{6,0,1,2,3,4,5}}));
  Solution s;
  for(int i = 0; i < test.size(); ++i)
    cout<<"Index: "<<s.amazingNumber(test[i])<<endl;

  return 0;

}
