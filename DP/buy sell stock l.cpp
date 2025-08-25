https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    void maxProfitFinder(vector<int>& prices, int i, int &minPrice, int &maxProfit) {
        if (i == prices.size()) return;  // base case

        // Update min price if today's price is lower
        if (prices[i] < minPrice) 
            minPrice = prices[i];

        // Profit if we sell today
        int todaysProfit = prices[i] - minPrice;

        // Update maxProfit if today's profit is better
        if (todaysProfit > maxProfit) 
            maxProfit = todaysProfit;

        // Recursive call
        maxProfitFinder(prices, i + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0; 
        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};
