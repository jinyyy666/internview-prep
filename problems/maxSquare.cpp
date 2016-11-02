#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<string>& matrix) {
        // idea: dp[i][j] maximum square can be achieved at point (i,j) that square must contain point (i,j) 
        // DP: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 if matrix[i][j] == 1, 0 if matrix[i][j] = 0
        int ret = 0;
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].length();
        vector<int> cur(n, 0);
        vector<int> pre(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0){
                    cur[j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j] == '0') cur[j] = 0;
                    else cur[j] = min(pre[j], min(cur[j-1], pre[j-1])) + 1;
                }
                ret = max(ret, cur[j]*cur[j]);
            }
            pre = cur;
        }
        return ret;
    }
};

int main(int argc, char ** argv){
  Solution s;

  vector<string> test = vector<string>({"11111111","11111110","11111110","11111000","01111000"});
  cout<<s.maximalSquare(test)<<endl;
  return 0;
}
