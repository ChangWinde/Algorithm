//  121. Best Time to Buy and Sell Stock
//  Say you have an array for which the ith element is the price of a given stock on day i.
//  If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//  Note that you cannot sell a stock before you buy one.
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int size = prices.size();
        int temp = prices[0];
        int q = 0;
        for(int i = 1;i<size;++i){
            if(prices[i]<temp)
                temp = prices[i];
            if((prices[i]-temp)>q)
                q = prices[i]-temp;
        }
        return q;
    }
};
