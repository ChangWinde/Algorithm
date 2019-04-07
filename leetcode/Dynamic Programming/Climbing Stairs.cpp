//  70. Climbing Stairs
//  You are climbing a stair case. It takes n steps to reach to the top.
//  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//  https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    long climbStairs(int n) {
        if(n<=2)
            return n;
        long ppre = 1;
        long pre = 2;
        long res;
        for(int i = 3;i<=n;++i){
            res = ppre+pre;
            ppre = pre;
            pre = res;
        }
        return res;
    }
};