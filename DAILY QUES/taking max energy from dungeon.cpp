https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10

//RECURSION 

// class Solution {
// public:
//     int solver(vector<int>& energy, int i, int k, int n) {
//         if (i >= n) {
//             return 0;
//         }
//         return energy[i] + solver(energy, i + k, k, n);
//     }

//     int maximumEnergy(vector<int>& energy, int k) {
//         int n = energy.size();
//         int ans = INT_MIN;

//         for (int start = 0; start < n; start++) {
//             ans = max(ans, solver(energy, start, k, n));
//         }
//         return ans;
//     }
// };



//TOP-DOWN

// class Solution {
// public:
//     int solver(vector<int>& energy, int i, int k, int n,vector<int>&dp){
//         if (i >= n) {
//             return 0;
//         }
//         if(dp[i]!=INT_MIN){
//             return dp[i];
//         }
//         dp[i]= energy[i] + solver(energy, i + k, k, n,dp);
//         return dp[i];
//     }

//     int maximumEnergy(vector<int>& energy, int k) {
//         int n = energy.size();
//         int ans = INT_MIN;
//         vector<int> dp(n+1, INT_MIN);

//         for (int start = 0; start < n; start++) {
//             ans = max(ans, solver(energy, start, k, n,dp));
//         }
//         return ans;
//     }
// };


//BOTTOM-UP
class Solution {
public:
    int solver(vector<int>& energy, int k, int n) {
        vector<int> dp(n+1, 0);
        int ans = INT_MIN;

        for (int i = n-1; i >= 0; i--) {
            dp[i] = energy[i];
            if (i + k < n)
                dp[i] += dp[i + k];
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        return solver(energy, k, n);
    }
};
