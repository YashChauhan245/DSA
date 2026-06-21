https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21


//APPORACH-1-->sorting + greedy (nlogn)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(),costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                count++;
                coins-=costs[i];
            }
            else{
                break;
            }
        }
        return count;

    }
};



//APPROACH-2 -->using freq array + greedy (o(n+k))

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        vector<int> freq(100001, 0);

        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;
        //process prices from cheapest to most expensive
        for (int price = 1; price <= 100000; price++) {
            //buy all ice creams for that price if possible
            while (freq[price] > 0 && coins >= price) {
                coins -= price;
                count++;
                freq[price]--;
            }
        }

        return count;
    }
};
