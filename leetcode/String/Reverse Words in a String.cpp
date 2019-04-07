//  151. Reverse Words in a String
//  Given an input string, reverse the string word by word.
//  https://leetcode.com/problems/reverse-words-in-a-string/

// it is not a good solution
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        int i = 0;
        while(i<s.size()){
            if(s[i] != ' ')
                break;
            i++;
        }
        if(i == s.size())
            return string("");
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        rever(s,0,s.size()-1);
        int start = -1;
        int pre = 0;
        int end = s.size()-1;
        while(start++ <= end){
            if(s[start] == ' '){
                rever(s,pre,start-1);
                pre = start+1;
                if(s[start+1] == ' '){
                    int num = 0;
                    while(s[start+1] == ' '){
                        num++;
                        start++;
                    }
                    s.erase(pre,num);
                    end = s.size()-1;
                    start = pre;
                }
            }
        }
       rever(s,pre,end);  
       return s;   
    }
    void rever(string &s,unsigned int start,unsigned int end){
        while(start < end){
            swap(s[start++],s[end--]);
        }
    }
};