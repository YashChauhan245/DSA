https://leetcode.com/problems/minimum-time-to-make-rope-colorful/submissions/1819958160/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        int prev = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[prev]) {
                totalTime += min(neededTime[i], neededTime[prev]);

                if (neededTime[i] > neededTime[prev])
                    prev = i;
            } else {
                prev = i;
            }
        }
        return totalTime;
    }
};
