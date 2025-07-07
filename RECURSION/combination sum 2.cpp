https://leetcode.com/problems/combination-sum-ii/submissions/1689397794/

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int target, vector<int>& temp, int start) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // If current candidate is greater than remaining target, break (since array is sorted)
            if (candidates[i] > target)
                break;

            // Include this candidate
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], temp, i + 1);
            
            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates easily
        vector<int> temp;
        solve(candidates, target, temp, 0);
        return result;
    }
};

