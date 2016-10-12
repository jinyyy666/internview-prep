#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>

using namespace std;

// my version of radix sort
class Solution{
public:
  // find the maximum value given an array with size n:
  int getMax(int arr[], int n){
    assert(arr != NULL && n > 1);
    int max = arr[0];
    for(int i = 1; i < n; ++i)
      max = arr[i] > max ? arr[i] : max;
    return max;
  }

  // count sort for each digit 
  // assume that the radix for the number is 10
  void countSort(int arr[], int n, int exp){
    assert(exp != 0);
    int * output = (int *)malloc(sizeof(int)*n);
    int index = 0;
    int count[10];
    memset(count, 0, sizeof(count));
    
    
    // count the digits:
    for(int i = 0; i < n; ++i){
      index = (arr[i]/exp) % 10;
      assert(index >= 0 && index < 10);
      count[index]++;
    }

    // compute the subarray sum of count so that we can have the indices:
    for(int i = 1; i < 10; ++i)
      count[i] += count[i-1];

    // sort the array based on count:
    // in this order because of dequeue:
    for(int i = n-1; i >=0; --i){
      index = (arr[i]/exp) % 10;
      output[count[index] -1] = arr[i];
      count[index]--;
    }

    // copy the result back to the array:
    for(int i = 0; i < n; ++i)
      arr[i] = output[i];
    
    free(output);
  }

  
  // print out the output array:
  void print(int arr[], int n){
    for(int i = 0; i < n; ++i)
      cout<<arr[i]<<"\t";
    cout<<endl;
  }

  void radixSort(int arr[], int n){
    // find out the max amount all its numbers:
    int max = getMax(arr, n);
    
    // begin the radix sort:
    for(int exp = 1; max/exp > 0; exp *= 10)
      countSort(arr, n, exp);
    
    // print the array:
    cout<<"The array after sorting: "<<endl;
    print(arr, n);
  }
};

int main(int argc, char** argv){
  Solution S;
  
  int* arr = (int *)malloc(sizeof(int)* (argc -1));
  for(int i = 1; i < argc; i ++){
     arr[i-1] = atoi(argv[i]);
  }
  
  //int arr [] = { 12 ,123, 12312, 42112, 13421, 1234,312, 314};
  //int n = sizeof(arr)/sizeof(int);
  cout<<"The array: "<<endl;
  S.print(arr, argc -1);
  S.radixSort(arr, argc -1);

  free(arr);
  return 0;

}
