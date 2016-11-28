/**************************************************************
 * Problem: Given a matrix h*w, and randomly generate m mines
 *************************************************************/

#include <vector>
#include <iostream>

using namespace std;
class Solution{
public:
  // idea: reservoir sampling
  vector<vector<int> > generate(int h, int w, int m){
    vector<vector<int> > matrix(h, vector<int>(w, 0));
    // reservoir sampling:
    for(int i = 0; i < h*w; ++i){
      if(i < m)  matrix[i/w][i%w] = i;
      else{
	int j = rand()%(i+1);
	if(j < m)  matrix[j/w][j%w] = i;
      }
    }

    // put the mines
    for(int i = 0; i < m; ++i){
      int val = matrix[i/w][i%w];
      matrix[i/w][i%w] = 0;
      matrix[val/w][val%w] = 1;
    }
    return matrix;
  }
  vector<vector<int> > generateOther(int h, int w, int m){
    vector<vector<int> > matrix(h, vector<int>(w, 0));
    
    // other's approach:
    int tail = h*w;
    for(int i = 0; i < m; ++i){
      tail--;
      matrix[tail/w][tail%w] = rand()%(tail+1);
    }

    for(int i = 0; i < m; ++i){
      int cur = matrix[tail/w][tail%w];
      matrix[cur/w][cur%w] = 1;
      matrix[tail/w][tail%w] = 0;
      tail++;
    }
  
    return matrix;
  }
};

void printMatrix(vector<vector<int> > v){
  int m = v.size(), n = v[0].size();
  cout<<"***************************"<<endl;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j)
      cout<<v[i][j]<<" ";
    cout<<endl;
  }
  cout<<"***************************"<<endl;
  cout<<endl;
}

int main(int argc, char ** argv){
  Solution s;
  vector<vector<int> > target({{1,0,1},{0,0,0},{0,1,0}});
  double cnt_r = 0, cnt_o;
  for(int i = 0; i < 1000000; i++){
    if(s.generateOther(3,3,3) == target)  cnt_o++;
    if(s.generate(3,3,3) == target) cnt_r++;
  }
  cout<<"The probablity obtained under reservoir: "<<cnt_r/1000000.0<<endl;
  cout<<"The probablity of another approach: "<<cnt_o/1000000.0<<endl;
  cout<<"The ideal probablity is "<<6.0/(9*8*7)<<endl;
  return 0;
}
