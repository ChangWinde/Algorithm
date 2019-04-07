//  45. Jump Game II
//  Given an array of non-negative integers, you are initially positioned at the first index of the array.
//  Each element in the array represents your maximum jump length at that position.
//  Your goal is to reach the last index in the minimum number of jumps.
//  https://leetcode.com/problems/jump-game-ii/

// slower(>40%) but less space(<75%) time O(n^2)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1){
            return 0;
        }
        int end = nums.size()-1;
        int pos = end - 1;
        int tempPos = pos;
        unsigned int count = 0;
        
        while(end != 0){
            while(pos>=0){
                if(nums[pos]>=(end-pos))
                    tempPos = pos;
                pos--;
            }
            count++;
            end = tempPos;
            pos = end-1;
        }
        return count;
    }
};
// I find a better one which uses O(n) for time(greedy)
class Solution {
public:
    int jump(vector<int>& nums) {
    int end = 0;
    int maxPosition = 0; 
    int steps = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        maxPosition = max(maxPosition, nums[i] + i); 
        if( i == end){ 
            end = maxPosition;
            steps++;
        }
    }
    return steps;
    }
};