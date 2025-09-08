https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0; 
        int n = garbage.size(); 
        int G = 0;
        int M = 0;
        int P = 0;
        
        int total = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < garbage[i].length(); j++) {   
                if(garbage[i][j] == 'M') {
                    M =  i;
                } else if(garbage[i][j] == 'P') {
                    P = i;
                } else {
                    G = i;
                }
                //picking time 
                total++;
            }
        }
        
        //sum for travel time
        for(int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }
        
        //If last house = 1 → need travel[0]
        // If last house = 2 → need travel[1]
        // So the -1 just adjusts the index shift
        total += M > 0 ? travel[M-1] : 0;
        total += P > 0 ? travel[P-1] : 0;
        total += G > 0 ? travel[G-1] : 0;
        
        return total;
        
    }
};





