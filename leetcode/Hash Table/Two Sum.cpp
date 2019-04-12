//  1. Two Sum
//  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//  You may assume that each input would have exactly one solution, and you may not use the same element twice.
//  https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return {};
        vector<int> res;
        if(n == 0)
            return res;
        unordered_map<int,int> temp;
        for(int i = 0;i<n;++i){
            if(temp.count(target-nums[i]) == 1){
                res.push_back(temp[target-nums[i]]);
                res.push_back(i);
                break;
            } 
            temp[nums[i]] = i;
        }
        return res;
    }
};