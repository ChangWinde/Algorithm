//  287. Find the Duplicate Number
//  Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//  https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<2)
            return -1;
        int fast = nums[nums[0]];
        int slow = nums[0];
        while((fast = nums[nums[fast]]) != (slow = nums[slow])){}
        slow = 0;
        while((fast = nums[fast]) != (slow = nums[slow])){}
        return fast;
    }
};

// the same as above but much more clearly
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
            return -1;
        if(nums.size()<3)
            return nums[0];
        int fast = nums[nums[0]];
        int slow = nums[0];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};