https://leetcode.com/problems/maximum-total-damage-with-spell-casting/?envType=daily-question&envId=2025-10-11


// class Solution {
// public:
//     typedef long long ll;
//     int n;                                
//     unordered_map<ll,ll> mp;      

//     // Pure recursive function without memoization
//     long long solve(int i, const vector<ll>& nums) {
//         if (i >= n) 
//             return 0;

//         // skip current damage
//         ll skip = solve(i + 1, nums);

//         // take current damage
//         int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
//         ll take = nums[i] * mp[nums[i]] + solve(j, nums);

//         return max(skip, take);
//     }

//     long long maximumTotalDamage(vector<int>& power) {
//         for (int x : power) 
//             mp[x]++;

//         vector<ll> nums;
//         for (auto &p : mp)
//             nums.push_back(p.first);

//         sort(begin(nums), end(nums));
//         n = nums.size();

//         return solve(0, nums);
//     }
// };




//TOP DOWN

// class Solution {
// public:
//     typedef long long ll;
//     int n;                                
//     unordered_map<ll,ll> mp;      
//     vector<ll> dp;  // DP array for memoization

//     // Recursive function with DP array
//     ll solve(int i, const vector<ll>& nums) {
//         if (i >= n) 
//             return 0;

//         if (dp[i] != -1) 
//             return dp[i];

//         // skip current damage
//         ll skip = solve(i + 1, nums);

//         // take current damage
//         int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3) - nums.begin();
//         ll take = nums[i] * mp[nums[i]] + solve(j, nums);
//         return dp[i] = max(skip, take);
//     }

//     ll maximumTotalDamage(vector<int>& power) {
//         // fill map 
//         for (int i = 0; i < power.size(); i++) {
//             mp[power[i]]++;
//         }

//         vector<ll> nums;
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             nums.push_back(it->first);
//         }

//         sort(nums.begin(), nums.end());
//         n = nums.size();
//         dp = vector<ll>(n+1, -1);
//         return solve(0, nums);
//     }
// };



//Bottom up

class Solution {
public:
    typedef long long ll;
    int n;
    unordered_map<ll,ll> mp;
    ll solve(const vector<ll>& nums) {
        vector<ll> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: skip current number
            ll skip = dp[i + 1];

            // Option 2: take current number
            int j = i + 1;
            while (j < n && nums[j] < nums[i] + 3) j++;
            ll take = nums[i] * mp[nums[i]] + (j < n ? dp[j] : 0);
            dp[i] = max(skip, take);
        }
        return dp[0];
    }

    ll maximumTotalDamage(vector<int>& power) {
        for (int i = 0; i < power.size(); i++) mp[power[i]]++;
        vector<ll> nums;
        for (auto it = mp.begin(); it != mp.end(); it++) nums.push_back(it->first);
        sort(nums.begin(), nums.end());
        n = nums.size();
        return solve(nums);
    }
};

