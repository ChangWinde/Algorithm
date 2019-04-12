//  405. Convert a Number to Hexadecimal
//  Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
//  https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        string note = "0123456789abcdef";
        string res = "";
        unsigned int n = num;
        if(num<0)
            n = ~(-num)+1;
        while(n>0){
            res = note[(n&15)]+res;
            n = n>>4;
        }
        return res;
    }
};
