//  344. Reverse String
//  Write a function that reverses a string. The input string is given as an array of characters char[].
//  Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//  https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty())
            return;
        int start = 0;
        int end = s.size()-1;
        char temp;
        while(start < end){
            temp = s[start];
            s[start++] = s[end];
            s[end--] = temp;
        }
    }
};