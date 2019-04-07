//  42. Trapping Rain Water
//  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//  https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
// faster solution
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
            return 0;
        int r = height.size()-1;
        int l = 0;
        int maxr = height[r];
        int maxl = height[l];
        int water = 0;
        while (l < r) {
            if(height[l]<height[r]){
                if(height[l]>maxl){
                    maxl = height[l];
                }else{
                    water += maxl-height[l];
                }
                l++;
            }else{
                if(height[r]>maxr){
                    maxr = height[r];
                }else{
                    water += maxr-height[r];
                }
                r--;
            }
        }
        return water;
    }
};