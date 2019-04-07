//  7. Reverse Integer
//  Given a 32-bit signed integer, reverse digits of an integer.
//  https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int dig;
        long long res = 0;
        while(x){
            dig = x % 10;
            res = res*10+dig;
            x = x/10;
        }
        return (res<INT_MIN || res>INT_MAX)?0:res;
    }
};