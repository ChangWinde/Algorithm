//  392. Is Subsequence
//  Given a string s and a string t, check if s is subsequence of t.
//  You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//  A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//  https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;
        if(t.empty())
            return false;
        char target = s[0];
        int k = 1,size = s.size();
        for(auto i:t){
            if(i == target){
                if(k<size)
                    target = s[k++];
                else
                    return true;
            }
        }
        return false;
    }
};