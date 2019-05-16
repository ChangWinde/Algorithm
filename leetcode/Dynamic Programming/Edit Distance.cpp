//  72. Edit Distance
//  Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//  You have the following 3 operations permitted on a word:
//  Insert a character
//  Delete a character
//  Replace a character
//  https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string w1, string w2) {
        int l1 = w1.size();
        int l2 = w2.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i = 0;i<=l1;++i)
            dp[i][0] = i;
        for(int j = 0;j<=l2;++j)
            dp[0][j] = j;
        for(int i = 1;i<=l1;++i){
            for(int j = 1;j<=l2;++j){
                if(w1[i-1] == w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
        return dp[l1][l2];
    }
};