//  338. Counting Bits
//  Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//  https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        //刚开始的就直接申请足够的空间，会比后来一点一点的加更快！
        vector<int> res(num+1,0);
        if(num<1)
            return res;
        res[1] = 1;
        int i = 1;
        int offset = 0;
        while(++i <= num){
            if((i&(i-1))==0){
                offset = 0;
            }
            res[i] = res[offset++]+1;
        }
        return res;
    }
};

//  brilliant solution
//  n&(n-1)可以将最右边的1变为0
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};