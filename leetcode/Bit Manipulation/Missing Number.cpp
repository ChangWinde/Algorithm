//  268. Missing Number
//  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//  https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int sum = 0;
        for(int i = 0;i<n;++i)
            sum += nums[i];
        return (n*(n+1))/2-sum;
    }
};

// 在这个解法中，你可以重新审视xor的效果，它可以做到不进位的按位加法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int res = 0;
        int i;
        for(i = 0;i<n;++i)
            res = res^i^nums[i];
        return res^i;         
    }
};
