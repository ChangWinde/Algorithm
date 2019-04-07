//  279. Perfect Squares
//  Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//  https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
            return 0;
        int* note =  new int[n+1]; 
        note[0] = 0;
        int min;
        for(int i = 1;i<=n;++i){
            min = INT_MAX;
            int j = 1;
            while(i-j*j>=0){
                min = min>note[i-j*j]+1?note[i-j*j]+1:min;
                ++j;
            }
            note[i] = min;
        }
        return note[n];
    }
};