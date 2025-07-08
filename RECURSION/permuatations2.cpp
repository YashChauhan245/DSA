https://leetcode.com/problems/permutations-ii/


class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, vector<int>& temp, unordered_map<int, int>& mp) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int num = it->first;
            int count = it->second;

            if (count == 0) continue;

            temp.push_back(num);
            mp[num]--; 

            solve(nums, temp, mp); 

            temp.pop_back();
            mp[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<int> temp;
        solve(nums, temp, mp);
        return result;
    }
};
