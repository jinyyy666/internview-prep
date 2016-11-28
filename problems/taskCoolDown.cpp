/****************************************************************************
 * Problem: Task cool down
 * Suppose you have a single-thread task scheduler and 4 threads.
 * After the execution of each thread, it needs to cool down for some time.
 * Ouput the minimum execution time
 * Eg 1:
 * tasks: 1, 1, 2, 1, recovery interval : 2
 * output: 7 (order is 1 _ _ 1 2 _ 1)
 * Eg 2:
 * tasks: 1, 2, 3, 1, 2, 3, recovery interval: 3
 * output: 7 (order is 1, 2, 3, _ 1, 2, 3)
 * Eg 3: 
 * tasks: 1, 2, 1, 1, 3, 4, recovery interval: 2
 * output: 9 (order is 1, 2, _, 1, _, _, 1, 3, 4)
 ***************************************************************************/
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution{
public:
  int taskCoolDown(vector<int>& tasks, int cooldown){
    // idea: Use a hash table to keep track of the most recent timestamp of each task
    // When a new task comes with a timestamp, if the hash table does not contain the new task
    // simple put the new task into the hash table; else update the timestamp of this task such 
    // that the cooldown condition is satisfy. Keep a max for the timestamp

    unordered_map<int, int> hash; // keep track of the most recent timestamp of each tasks
    int maxLen = 0;
    for(int i = 0; i < tasks.size(); ++i){
      if(hash.find(tasks[i]) == hash.end()){
	hash[tasks[i]] = i;
      }
      else{
	if(i - hash[tasks[i]] - 1 < cooldown){
	  hash[tasks[i]] += cooldown+1;
	}
	else hash[tasks[i]] = i;	
      }
      maxLen = max(hash[tasks[i]], maxLen);
    }
    return maxLen + 1;
  }
};

int main(int argc, char ** argv){
  Solution s;
  vector<vector<int> > tests({{1,1,2,1},{1,2,3,1,2,3},{1, 2, 1, 1, 3, 4}});
  vector<int> recover({2, 3, 3});
  for(int i = 0; i < 3; ++i){
    cout<<"Total time: "<<s.taskCoolDown(tests[i], recover[i])<<endl;
  }
  return 0;
}
