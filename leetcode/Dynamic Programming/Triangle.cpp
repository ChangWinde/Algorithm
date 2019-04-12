//  120. Triangle
//  Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//  https://leetcode.com/problems/triangle/

// very slow but use less space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        int m = triangle.size();
        int n = m*(m+1)/2;
        vector<int> dp(n+1,0);
        int j;
        for(int i = m*(m-1)/2+1,j = 0;i<=n;++i)
            dp[i] = triangle[m-1][j++];
        while(--m){
            int start = m*(m-1)/2+1;
            int end = start+m;
            for(int i = start,j=0;i<end;++i,++j)
                dp[i] = triangle[m-1][j]+min(dp[end+j],dp[end+j+1]);
        }
        return dp[1];
    }
};
// other idea from leecode discuss,less space than me and a little faster than me
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        int m = triangle.size();
        vector<int> dp(triangle.back());
        for(int i = m-2;i>=0;--i){
            for(int j = 0;j<=i;++j){
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        return dp[0];
    }
};