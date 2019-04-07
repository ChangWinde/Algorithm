//  441. Arranging Coins
//  You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
//  Given n, find the total number of full staircase rows that can be formed.
//  n is a non-negative integer and fits within the range of a 32-bit signed integer.
//  https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2)
            return n;
        int count = 1;
        while(n>=count){
            n -= count++;
        }
        return count-1;
    }
};