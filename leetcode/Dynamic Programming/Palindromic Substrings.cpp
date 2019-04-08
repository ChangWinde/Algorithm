//  647. Palindromic Substrings
//  Given a string, your task is to count how many palindromic substrings in this string.
//  The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

//构造单双核的回文串
class Solution {
public:
    int len;
    int count;
    int countSubstrings(string s) {
        len = s.size();
        count = 0;
        for (int i = 0; i < len; i++) {
            addOne(s,i,i);   //single-core
            addOne(s,i,i+1); //double-core
        }
        return count;
    }
    void addOne(string s,int l,int r){
        while(((l>=0)&&(r<len))&&(s[r++]==s[l--])){
            count++;
        }
    }
};