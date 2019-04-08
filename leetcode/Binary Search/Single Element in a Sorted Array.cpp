//  540. Single Element in a Sorted Array
//  Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
//  https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    //recursion version
    int smallSingle(vector<int>& nums,int l,int r){
        if(l<r){
            int mid = (l+r)/2;
            if(nums[mid]==nums[mid+1]){
                if((mid & 0x1) == 0){
                    return smallSingle(nums,mid+2,r);
                }else{
                    return smallSingle(nums,l,mid-1);
                }
            }else if(nums[mid]==nums[mid-1]){
                if((mid & 0x1) == 0){
                    return smallSingle(nums,l,mid-2);
                }else{
                    return smallSingle(nums,mid+1,r);
                }
            }else{
                return nums[mid];
            }
        }
        
        return nums[l];
    }
    // iteration version be faster and less space
    int samllSingle2(vector<int>& nums,int l,int r){
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]==nums[mid+1]){
                ((mid & 0x1) == 0)?l=mid+2:r=mid-1;
            }else if(nums[mid]==nums[mid-1]){
                ((mid & 0x1) == 0)?r=mid-2:l=mid+1;
            }else{
                return nums[mid];
            }
        }
        return nums[l];
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()<1)
            return 0;
        return samllSingle2(nums,0,nums.size()-1);
    }
    
};