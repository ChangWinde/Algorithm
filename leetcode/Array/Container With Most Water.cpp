//  11. Container With Most Water
//  Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
//  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//  Note: You may not slant the container and n is at least 2.
//  https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int end = height.size()-1;
        int start = 0;
        int ht = min(height[start],height[end]);
        int width;
        int area = 0;
        while(start < end){ 
            width = end - start;
            ht = (height[start] >= height[end])?height[end--]:height[start++];
            if(area<ht*width){
                area = ht*width;
            }
        }
        return area;
    }
};
