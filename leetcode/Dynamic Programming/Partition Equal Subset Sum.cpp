//  416. Partition Equal Subset Sum
//  Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//  https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return (size+1) & 0x1;
        // if sum is even,it is absolutely false
        int sum = 0;
        for(int i = 0;i<size;++i)
            sum += nums[i];
        if(sum & 0x1)
            return false;
        sum /= 2;
        
        bool* flags = new bool[sum+1]{0};
        flags[0] = true;
        for(int i = 0;i<size;++i){
            for(int j = sum;j>=nums[i];--j)
                flags[j] = flags[j] || flags[j-nums[i]];
        }
        return flags[sum];
    }
};