https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];  // same start -> bigger end first
            }
            return a[0] < b[0];      // smaller start first
        });

        int ans = 0;
        int maxEnd = 0;

        for (int i=0;i<intervals.size();i++){
            if (intervals[i][1] > maxEnd) {   
                ans++;
                maxEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
