//  926. Flip String to Monotone Increasing
//  A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)
//  We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.
//  Return the minimum number of flips to make S monotone increasing.
//  https://leetcode.com/problems/flip-string-to-monotone-increasing/

// 思路：使用note[i]表示[0,i]之间1的个数
//       temp计算的是每个位置需要flip的个数 temp = (n-1-note[n-1])-(i-note[i]) (if S[i] == '0'则temp++) 
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        if(S.empty())
            return 0;
        int n = S.size();
        vector<int> note(n,0);
        note[0] = (S[0] == '1')?1:0;
        for(int i = 1;i<n;++i){
            if(S[i] == '1')
                note[i] = note[i-1]+1;
            else
			    note[i] = note[i-1];
        }
        int con = n-1-note[n-1];
        int min = con+note[0]+(note[0]==1?0:1);
        int temp;
        for(int i = 1;i<n;++i){
            temp = con-i+note[i]+note[i-1];
            if(S[i] == '0')
                temp++;
            min = min<temp?min:temp;
        }
        return min<note[n-1]?min:note[n-1];
    }
};