//  5. Longest Palindromic Substring
//  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//  https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int len;
    int start,max;
    string longestPalindrome(string s) {
        len = s.size();
        max = 0;
        if(len<2)
            return s;
        for (int i = 0; i < len; i++) {
            addOne(s,i,i);   //single-core
            addOne(s,i,i+1); //double-core
        }
        return s.substr(start,max);
    }
    void addOne(string s,int l,int r){
        while(((l>=0)&&(r<len))&&(s[r]==s[l])){r++,l--;}
        int count = r-l-1;
        if(count>max){
            max = count;
            start = l+1;
        }
    }
};