#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class RandomizedSet {
private: 
    vector<int> m_nums;
    unordered_map<int, int> m_hash;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m_hash.find(val) == m_hash.end()){
            m_nums.push_back(val);
            m_hash[val] = m_nums.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m_hash.find(val) == m_hash.end())    return false;
        int index = m_hash[val]; // get its index;
        int last = m_nums.back();
        swap(m_nums[index], m_nums.back()); // get rid of this number in m_num
        m_hash[last] = index; // assign the original index of the evicted number to the last number
        m_nums.pop_back();
        m_hash.erase(val); // get rid of this number;

        return true;
        
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(m_nums.empty())  return -1;
        return m_nums[rand() % m_nums.size()];
    }
};

int main(int argc, char ** argv){
  RandomizedSet r;

  cout<<r.insert(0)<<endl;
  cout<<r.remove(0)<<endl;
  cout<<r.insert(-1)<<endl;
  cout<<r.remove(0)<<endl;

  return 0;
}
