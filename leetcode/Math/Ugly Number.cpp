//  263. Ugly Number
//  Write a program to check whether a given number is an ugly number.
//  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//  https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
        if(!num)
            return false;
        vector<int> prime = {2,3,5};
        for(int i = 0;i<3;++i){
            int factor = prime[i];
            while(num%factor == 0)
                num /= factor;
        }
        return num==1?true:false;
    }
};