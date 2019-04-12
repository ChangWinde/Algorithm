//  983. Minimum Cost For Tickets
//  In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.
//  Train tickets are sold in 3 different ways:
//  a 1-day pass is sold for costs[0] dollars;
//  a 7-day pass is sold for costs[1] dollars;
//  a 30-day pass is sold for costs[2] dollars.
//  The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
//  Return the minimum number of dollars you need to travel every day in the given list of days.
//  https://leetcode.com/problems/minimum-cost-for-tickets/

//  dp[0][i]表示 第i天买7-day票可以包含几天  example：dp[0][5] = 6  表示=>第五天买七天票有五天可以使用
//  dp[1][j]表示 第j天买30-day票可以包含几天 example：dp[1][5] = 20 表示=>第五天买三十天票有二十天可以使用
//  递推规则：
//  dp[0][i] = dp[0][i-1]-1+(从days[i+dp[i-1]-1]开始算还有几天可以使用dp[0][i]买的票)
//  pay[i]表示从第i天到最后一天最小花费
//  pay[i] = min{pay[i+1]+costs[0],pay[i+dp[0][i]]+costs[1],pay[i+dp[1][i]]+costs[2]};
class Solution {
public:
    int mymin(int a,int b,int c){
        a = a<b?a:b;
        return a<c?a:c;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        vector<vector<int>> dp(2,vector<int>(size,0));
        vector<int> pay(size,mymin(costs[0],costs[1],costs[2]));
        pay.push_back(0);
        int stand = days[0];
        for(int i = 0;i<size;++i){
            if(days[i]-stand<7)
                dp[0][0]++;
            if(days[i]-stand<30)
                dp[1][0]++;
        }
        for(int i = 1;i<size;++i){
            dp[1][i] = dp[1][i - 1] - 1;
            for (int j = i + dp[1][i]; j < size; ++j) {
                dp[1][i] = (days[j] - days[i]) <= 29 ? dp[1][i] + 1 : dp[1][i];
                if (dp[1][i] == 30)
                    break;
            }
            dp[0][i] = dp[0][i - 1] - 1;
            for (int j = i + dp[0][i]; j < size; ++j) {
                dp[0][i] = (days[j] - days[i]) <= 6 ? dp[0][i] + 1 : dp[0][i];
                if (dp[0][i] == 7)
                    break;
		    }
        }
        for(int i = size-2;i>=0;--i){
            pay[i] = mymin(pay[i+1]+costs[0],pay[i+dp[0][i]]+costs[1],pay[i+dp[1][i]]+costs[2]);
        }
        return pay[0];
    }
};