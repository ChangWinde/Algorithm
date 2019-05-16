//  718. Maximum Length of Repeated Subarray
//  Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(),n = B.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int mmax = -1;
        for(int i = 1;i<=m;++i){
            for(int j = 1;j<=n;++j){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = 0;
                }
                mmax = max(mmax,dp[i][j]);
            }
        }
        return mmax;
    }
};