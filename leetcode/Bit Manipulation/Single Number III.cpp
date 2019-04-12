//  260. Single Number III
//  Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//  https://leetcode.com/problems/single-number-iii/

// idea：首先获得所有数字的异或值，这样出现两次的数字就会消失，最终的结果就是出现了一次的两个数字的异或值
//       求出这个异或这最右边的1的位置（两个数字一定不同，所以一定是有1的）
//       对所有数字进行分组，（比如上一步求出第i个位置为1），则根据第i个位置是不是1分成两组，这个两个数字就分别在这两个组中
//       再对两个数组连续异或即可
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return {};
        int x = 0;
        for(int i = 0;i<size;++i){
            x ^= nums[i];
        }
        x = x&(x-1)^x;
        int a = 0;
        int b = 0;
        for(int i = 0;i<size;++i){
            (nums[i]&temp)>0?(a ^= nums[i]):(b ^= nums[i]);
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};