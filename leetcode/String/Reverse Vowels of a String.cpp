//  345. Reverse Vowels of a String
//  Write a function that takes a string as input and reverse only the vowels of a string.
//  https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        string stand = "AEIOUaeiou";
        while(i<j){
            i = s.find_first_of(stand,i);
            j = s.find_last_of(stand,j);
            if(i>=j){
                break;
            }
            swap(s[i++],s[j--]);
        }
        return s;
    }
};