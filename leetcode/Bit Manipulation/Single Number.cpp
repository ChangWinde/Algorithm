//  136. Single Number
//  Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//  https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int res = 0;
        while(n--){
            res ^= nums[n];
        }
        return res;
    }
};