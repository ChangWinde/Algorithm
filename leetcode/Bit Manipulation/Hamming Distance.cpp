//  461. Hamming Distance
//  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//  Given two integers x and y, calculate the Hamming distance.
//  https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x^y;
        int count = 0;
        while(res>0){
            res = res&(res-1);
            count++;
        }
        return count;
    }
};
