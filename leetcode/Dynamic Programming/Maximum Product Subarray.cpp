//  152. Maximum Product Subarray
//  Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//  https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int myMax(int a,int b,int c){
        a = a>b?a:b;
        return a>c?a:c;
    }
    int myMin(int a,int b,int c){
        a = a<b?a:b;
        return a<c?a:c;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> p(n,0);
        p[0] = max(0,nums[0]);
        int one = nums[0];
        int two;
        int temp = nums[0];
        for(int i = 1;i<n;++i){
            two  = min(myMin(0,nums[i],nums[i]*one),nums[i]*p[i-1]);
            p[i] = max(myMax(0,nums[i],nums[i]*one),nums[i]*p[i-1]);
            one = two;
            temp = (temp>p[i])?temp:p[i];
        }
        return temp;
    }
};