https://leetcode.com/problems/russian-doll-envelopes/description/?envType=study-plan-v2&envId=binary-search


// sort+lis

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();

        // If there are no envelopes, we can't nest anything, so answer is 0
        if(n == 0) return 0;

        // Sort envelopes:
        // - First by width in increasing order (small → big)
        // - If two envelopes have same width, sort height in decreasing order (big → small)
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y){
            if(x[0] == y[0]) 
                return x[1] > y[1]; // Taller height comes first when width is same
            return x[0] < y[0]; // Smaller width comes first
        });


        // (LIS = longest valid nesting based on height after sorting)
        vector<int> ans;
        // Push the height of first envelope (after sorting)
        ans.push_back(a[0][1]);

        // Start checking from 2nd envelope to last
        for(int i = 1; i < n; i++) {
            int h = a[i][1]; // current envelope height

            // If current height is greater than last stored height in ans,
            // it means we can nest it, so add it to sequence
            if(h > ans.back()) {
                ans.push_back(h);
            } 
            // Else, find the position where this height should be placed
            // using binary search (`lower_bound`) to maintain smallest sequence
            else {
                int idx = lower_bound(ans.begin(), ans.end(), h) - ans.begin();
                ans[idx] = h; // replace the value at found position
            }
        }
        return ans.size();
    }
};
