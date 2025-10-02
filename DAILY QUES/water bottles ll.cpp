https://leetcode.com/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-10-02

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            //so exchange possible
            empty-=numExchange;
            numExchange++;
            numBottles++;//drunk++
            empty++;
        }
        return numBottles;//drunk++
    }
};
