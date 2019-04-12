//  63. Unique Paths II
//  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//  Now consider if some obstacles are added to the grids. How many unique paths would there be?
//  https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        vector<vector<long>> dp(m,vector<long>(n,0));
        dp[m-1][n-1] = 1;
        for(int i = n-2;i>=0;--i){
            dp[m-1][i] = (obstacleGrid[m-1][i]==1)?0:dp[m-1][i+1];
        }
        for(int i = m-2;i>=0;--i){
            dp[i][n-1] = (obstacleGrid[i][n-1]==1)?0:dp[i+1][n-1];
        }
        for(int i = m-2;i>=0;--i){
            for(int j = n-2;j>=0;--j){
                dp[i][j] = (obstacleGrid[i][j] == 1)?0:dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};