https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1676066384/

// class Solution {
// public:

// BRUTE:O(N2)-->TLE;

//     int maxProfit(vector<int>& prices) {
//         int profit=0;
//         int n=prices.size();
//         int maxprof=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(prices[i]<prices[j]){
//                     profit=prices[j]-prices[i];
//                     maxprof=max(maxprof,profit);
//                 }
//             }
//         }
//         return maxprof;
        
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // update minimum price seen so far
            } else {
                int profit = prices[i] - minPrice;
                if (profit > maxProfit) {
                    maxProfit = profit; // update max profit
                }
            }
        }

        return maxProfit;
    }
};
