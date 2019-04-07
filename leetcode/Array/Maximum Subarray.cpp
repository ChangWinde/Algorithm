//  53. Maximum Subarray
//  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//  https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int temp = nums[0];
        int max = temp;
        unsigned int size = nums.size();
        for(int i = 1;i<size;++i){
            if(temp<0 && nums[i]>temp)
                temp = 0;
            temp += nums[i];
            if(temp>max)
                max = temp;
        }
        return max;
    }
};