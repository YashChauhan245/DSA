https://leetcode.com/problems/merge-intervals/

// tc->o(nlogn)

//also take a at lc submission
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> prev = res.back();     // copy
            vector<int> curr = intervals[i];

            if (curr[0] > prev[1]) {
                res.push_back(curr);
            } else {
                prev[1] = max(prev[1], curr[1]); // modify copy
                res.back() = prev;               // update  res
            }
        }

        return res;
    }
};
