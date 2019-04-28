//  322. Coin Change
//  You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//  https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0)
            return -1;
        int coinLen = coins.size();
        sort(coins.begin(),coins.end(),less<int>());
        if(amount%coins[coinLen-1] == 0)
            return amount/coins[coinLen-1];
        vector<int> dp(amount,amount+1);
        dp.push_back(0);
        for(int i = amount;i>0;--i){
            for(int j = 0;j<coinLen;++j){
                if(i-coins[j]<0)
                    break;
                dp[i-coins[j]] = min(dp[i-coins[j]],dp[i]+1);
            }
        }
        return  (dp[0]==amount+1)?-1:dp[0];
    }
};