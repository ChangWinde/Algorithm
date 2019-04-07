//  55. Jump Game
//  Given an array of non-negative integers, you are initially positioned at the first index of the array.
//  Each element in the array represents your maximum jump length at that position.
//  Determine if you are able to reach the last index.
//  https://leetcode.com/problems/jump-game/

// for my natural idea(Recursive) faster(>99%) but use more space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()||nums.size() == 1)
            return true;
        bool flag = false;
        int pos = nums.size()-2;
        int end = nums.size()-1;
        while(pos>=0){
            if(nums[pos]>=(end-pos)){
                flag = true;
                break;
            }
            pos--;
        }
        return flag && help(nums,pos);
    }
    bool help(vector<int>& nums,int end) {
        if(end == 0)
            return true;
        bool flag = false;
        int pos = end -1;
        while(pos>=0){
            if(nums[pos]>=(end-pos)){
                flag = true;
                break;
            }
            pos--;
        }
        return flag && help(nums,pos);
    }
};

// second idea(iteration) slower but less space(<92.84%)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()||nums.size() == 1)
            return true;
        int pos = nums.size()-2;
        int end = nums.size()-1;
        while(pos>=0){
            if(nums[pos]>=(end-pos)){
                end = pos;
                pos = end -1;
                continue;
            }
            pos--;
        }
        if(end == 0)
            return true;
        else
            return false;
    }

};