#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int>& nums, int l, int r){
        if(l < r){
            int m = l + (r-l)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);
            merge(nums, l, m, r);
        }
    }

    void merge(vector<int>& nums, int l, int m, int r){
        int n1 = m-l + 1;
        int n2 = r - m;
        vector<int> L(n1);
        vector<int> R(n2);
        for(int i = 0; i < n1; ++i) L[i] = nums[l+i];
        for(int j = 0; j < n2; ++j) R[j] = nums[m+1+j];
        int i = 0, j = 0, k = l; 
        // begin merging:
        while(i < n1 || j < n2){
            if(i < n1 && j < n2)
                nums[k++] = L[i] < R[j] ? L[i++] : R[j++];
            else if(i < n1)
                nums[k++] = L[i++];
            else
                nums[k++] = R[j++];
        }
    }
    void quickSort(vector<int>& nums, int l, int r){
        int m = partition(nums, l, r);
        if(l < m-1)
	  quickSort(nums, l, m-1);
        if(m < r)
          quickSort(nums, m, r);
        
    }
    int partition(vector<int>& nums, int left, int right){
        int l = left, r= right;
        int pivot = nums[l + (r-l)/2];
        while(l <= r){
            while(nums[l] < pivot)  l++;
            while(nums[r] > pivot)  r--;
            if(l <= r)
	      swap(nums[l++], nums[r--]);
        }
        
        return l;
    }
};

void print(vector<int>& nums){
  for(int & n : nums)
    cout<<n<<"\t";
  cout<<endl;
}

int main(int argc, char ** argv){
    Solution s;
    vector<vector<int> > tests = {{2}, {5,2}, {4,1,3,9,8},{2,1,3,1},{10,9,7,6,5,4,3,2,1}};
    cout<<"Testing merge sort:"<<endl;
    for(auto v : tests){
        s.mergeSort(v, 0, v.size()-1);
        print(v);
    }
    cout<<"Testing quick sort:"<<endl;
    for(auto v : tests){
        s.quickSort(v, 0, v.size()-1);
        print(v);
    }   
 
}
