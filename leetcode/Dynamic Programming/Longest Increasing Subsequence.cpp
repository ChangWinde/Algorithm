//  300. Longest Increasing Subsequence
//  Given an unsorted array of integers, find the length of longest increasing subsequence.
//  https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n,1);
        int mmax = 0;
        for(int i = 1;i<n;++i){
            int temp = 0;
            for(int j = 0;j<i;++j){
                temp = (nums[j]<nums[i])?dp[j]+1:1;
                mmax = mmax>temp?mmax:temp;
            }
            dp[i] = mmax;
            mmax = 0;
        }
        for(int i = 0;i<n;++i)
            mmax = mmax>dp[i]?mmax:dp[i];
        return mmax;
    }
};