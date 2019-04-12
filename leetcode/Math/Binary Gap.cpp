//  868. Binary Gap
//  Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.
//  If there aren't two consecutive 1's, return 0.

class Solution {
public:
    int binaryGap(int N) {
        if(N==0)
            return 0;
        int k = N&(N-1)^N;
        int q;
        int max = 0;
        while(N){
            N = N&(N-1);
            q = N&(N-1)^N;
            int temp = log(q/k)/log(2);
            max = max>temp?max:temp;
            k = q;
        }
        return max;
    }
};
