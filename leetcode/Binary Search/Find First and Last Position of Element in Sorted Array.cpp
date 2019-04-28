//  34. Find First and Last Position of Element in Sorted Array
//  Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//  Your algorithm's runtime complexity must be in the order of O(log n).
//  If the target is not found in the array, return [-1, -1].
//  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
            return {-1,-1};
        int index = binarySearch(nums,target,0,size-1);
        if(index == -1)
            return {-1,-1};
        int i = index;
        int j = index;
        while(i>=0 && nums[index] == nums[i])i--;
        while(j<size&& nums[index] == nums[j])j++;
        i++;
        j--;
        return {i,j};
    }
    int binarySearch(vector<int>& nums, int target,int l,int r){
        if(l>r)
            return -1;
        int mid = (l+r)/2;
        if(target>nums[mid]){
            return binarySearch(nums,target,mid+1,r);
        }else if(target<nums[mid]){
            return binarySearch(nums,target,l,mid-1);
        }else{
            return mid;
        }
    }
};