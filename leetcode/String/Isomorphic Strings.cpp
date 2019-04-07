//  205. Isomorphic Strings
//  Given two strings s and t, determine if they are isomorphic.
//  Two strings are isomorphic if the characters in s can be replaced to get t.
//  All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//  https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char a[256] = {0};
        char b[256] = {0};
        unsigned int len = s.size();
        for(int i = 0;i<len;++i){
            if(a[s[i]] == 0 && b[t[i]] == 0){
                a[s[i]] = t[i];
                b[t[i]] = s[i];
            }else{
                if(a[s[i]] != '0' && a[s[i]] != t[i])
                    return false;
                if(b[t[i]] != '0' && b[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
/* I find a better soluton by other
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
*/
/* another smart solution by python
def isIsomorphic(self, s, t):
        return len(set(zip(s, t))) == len(set(s)) and len(set(zip(t, s))) == len(set(t))
*/