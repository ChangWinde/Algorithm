//  191. Number of 1 Bits
//  Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
//  https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0){
            n = n&(n-1);
            count++;
        }
        return count;
    }
};