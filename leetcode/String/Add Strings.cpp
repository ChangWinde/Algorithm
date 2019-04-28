//  415. Add Strings
//  Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//  https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string s1, string s2) {
        string res;
        int i = s1.size()-1, j = s2.size()-1;
        int add = 0;
        for (; j >= 0 && i >= 0; --j, --i) {
            add += (s1[i] - '0') + (s2[j] - '0');
            res = to_string(add % 10) + res;
            add /= 10;
        }
        if(i==j && add!=0){
             res = "1" + res;
        }
        if (i >= 0) {
            while (i >= 0 && add != 0) {
                add += (s1[i] - '0');
                res = to_string(add % 10) + res;
                add /= 10;
                --i;
            }
            if (add != 0)
                res = "1" + res;
            while (i >= 0) {
                res = s1[i] + res;
                --i;
            }
        }
        if (j >= 0) {
            while (j >= 0 && add != 0) {
                add += (s2[j] - '0');
                res = to_string(add % 10) + res;
                add /= 10;
                --j;
            }
            if (add != 0)
                res = "1" + res;
            while (j >= 0) {
                res = s2[j] + res;
                --j;
            }
        }
        return res;
    }
};
// the remedy from discussion
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            long sum = 0;
            if(i >= 0){sum += (num1[i] - '0');i--;}
            if(j >= 0){sum += (num2[j] - '0');j--;}
            sum += carry; 
            carry = sum / 10;
            sum = sum % 10;
            res =  to_string(sum)+res;
        }
        return res;
    }
};