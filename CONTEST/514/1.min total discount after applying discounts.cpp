https://leetcode.com/problems/minimum-total-price-after-applying-discounts/description/

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        double ans=0;
        int n=prices.size();
        int m=discounts.size();

        int k=min(n,m);
        for(int i=0;i<k;i++){
            ans+=prices[i]*(100.0-discounts[i])/100.0;
        }

        for(int i=k;i<n;i++){
            ans+=prices[i];
        }
        return ans;
    }
};
