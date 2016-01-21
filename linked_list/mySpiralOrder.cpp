#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>
#include <vector>

using namespace std;

// my solution of printing matrix in spiral order:
class Solution{
public:
  vector<int> spiralOrder(vector<vector<int> >& matrix){
    // idea: using the notion of four directions:
    vector<int> ret;
    if(matrix.empty()) return ret;
    const int dirx[] = {0, 1, 0, -1};
    const int diry[] = {1, 0, -1, 0};
    int row = matrix.size(), col = matrix[0].size();
    int x = 0, y = -1; // initial location
    int dir = 0; // indicating the directions for each print of entire row or col

    while(row > 0 && col > 0){
      int step;
      if(dir % 2 == 0)  step = col, row--; // for right or left direction
      else  step = row, col--;

      while(step--){ // run number of "step" steps
	x += dirx[dir], y += diry[dir];
	ret.push_back(matrix[x][y]);
      } 
      dir = (dir + 1)%4; // update for the next direction
    }

    return ret;
  }
  
};

int main(int argc, char** argv){
  Solution S;
  cout<<"Please type in two positive integer for the matrix dimension (separated by space): "<<endl;
  int row, col;
  cin>>row>>col;
  if(row < 0 || col <  0){
    cout<<"Invalid matrix size!! "<<row<<" "<<col<<endl;
    return -1;
  }

  cout<<"Please type in "<<row*col<<" integers to full in the matrix: "<<endl;
  vector<vector<int> > ret(row, vector<int>(col, 0));
  int num;
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      if(cin>>num)
	ret[i][j] = num;
      else
	ret[i][j] = 0;
    }
  }

  vector<int> order = S.spiralOrder(ret);

  cout<<"Print out the matrix in spiral order: "<<endl;
  for(int i = 0; i < order.size(); ++i)
    cout<<order[i]<<"\t";

  cout<<endl;
  return 0;

}
