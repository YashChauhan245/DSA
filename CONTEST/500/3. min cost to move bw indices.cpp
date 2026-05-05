https://leetcode.com/problems/minimum-cost-to-move-between-indices/description/

//Apporach-->prefix sum 
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Step 1: closest array
        vector<int> closest(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                closest[i] = 1;
            } else if (i == n - 1) {
                closest[i] = n - 2;
            } else {
                int left = abs(nums[i] - nums[i - 1]);
                int right = abs(nums[i] - nums[i + 1]);

                if (left <= right) closest[i] = i - 1;
                else closest[i] = i + 1;
            }
        }

        // Step 2: forward prefix (i -> i+1)
        vector<long long> prefF(n, 0);
        for (int i = 0; i < n - 1; i++) {
            long long cost = nums[i + 1] - nums[i];
            if (closest[i] == i + 1) cost = 1;
            prefF[i + 1] = prefF[i] + cost;
        }

        // Step 3: backward prefix (i -> i-1)
        vector<long long> prefB(n, 0);
        for (int i = n - 1; i > 0; i--) {
            long long cost = nums[i] - nums[i - 1];
            if (closest[i] == i - 1) cost = 1;
            prefB[i - 1] = prefB[i] + cost;
        }

        // Step 4: answer queries
        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            if (l <= r) {
                ans.push_back(prefF[r] - prefF[l]);
            } else {
                ans.push_back(prefB[r] - prefB[l]);
            }
        }

        return ans;
    }
};
