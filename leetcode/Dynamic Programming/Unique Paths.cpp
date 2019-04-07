//  62. Unique Paths
//  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//  How many possible unique paths are there?
//  https://leetcode.com/problems/unique-paths/

// use formula C(m+n-2,n-1)
class Solution {
public:
    //res = C(m+n-2,n-1)
    int uniquePaths(int m, int n) {
        if(m*n<0)
            return 0;
        if(m==1||n==1)
            return 1;
        int N = m+n-2;
        int M = n-1;
        double res = 1;
        for(int i = 1;i<=M;++i){
            res = res*(N-M+i)/i;
        }
        return (int)res;
    }
};
// faster but use more space
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m*n<0)
            return 0;
        if(m==1||n==1)
            return 1;
        vector<vector<int>> notes(m,vector<int>(n,1));
        int i,j;
        for(i = 1;i<m;++i){
            for(j = 1;j<n;++j){
                notes[i][j] = notes[i-1][j]+notes[i][j-1];
            }
        }
        return notes[i-1][j-1];
    }
};