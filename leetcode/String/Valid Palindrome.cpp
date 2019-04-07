//  125. Valid Palindrome
//  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//  Note: For the purpose of this problem, we define empty string as valid palindrome.
//  https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        unsigned int start = 0;
        unsigned int end = s.size()-1;
        bool ss = false;
        bool se = false;
        while(start < end){
            if(isdigit(s[start]) || isalpha(s[start]))
                ss = true;
            if(isdigit(s[end]) || isalpha(s[end]))
                se = true;
            if(ss&&se){
                if((s[start] | 32)!=(s[end] | 32))
                    return false;
                ss=se=false;
            }
            if(!ss)
                start++;
            if(!se)
                end--;
        }
        return true;
    }
};