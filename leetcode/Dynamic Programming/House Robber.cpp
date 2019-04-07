//  198. House Robber
//  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//  https://leetcode.com/problems/house-robber/

// faster than 100% and use less space than 100%
class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int first = nums[0];
        int second = max(nums[0],nums[1]);
        int size = nums.size();
        
        for(int i = 2;i<size;++i){
            int better = max(first+nums[i],second);
            first = second;
            second = better;
        }
        return max(first,second);
    }
};