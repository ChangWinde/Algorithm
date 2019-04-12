//  221. Maximal Square
//  Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//  https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int abs(char a,char b){
        return a>b?(a-b):(b-a);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
       vector<vector<int>> dp(m,vector<int>(n,0));
        int mmax = 0;
       for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                dp[i][j] = matrix[i][j]-'0';
                if(i==0||j==0||dp[i][j] == 0){
                    mmax = (mmax<dp[i][j])?dp[i][j]:mmax;
                    continue;
                }  
                int gap = abs(dp[i-1][j],dp[i][j-1]);
                if(gap == 0){
                    int temp = dp[i-1][j];
                    dp[i][j] = (matrix[i-temp][j-temp] == '1')?temp+1:temp;
                }else if(gap == 1){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }else if(gap >= 2)
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                mmax = (mmax<dp[i][j])?dp[i][j]:mmax;
            }
        }
        return mmax*mmax;
    }
};

// a better solution from discuss 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};