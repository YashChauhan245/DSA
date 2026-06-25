https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25

//Brute -->find all subarrya and then find the valid subarray then return count 

// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         long long ans = 0;

//         for (int i = 0; i< n; i++) {
//             int targetCount = 0;

//             for (int j= i;j < n; j++) {
//                 if (nums[j] == target) {
//                     targetCount++;
//                 }

//                 int len = j - i + 1;

//                 if (targetCount > len / 2) {
//                     ans++;
//                 }
//             }
//         }

//         return ans;
//     }
// };


//tc->o(n2)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        
        //making prefix subarray
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        long long ans = 0;
        
        //checking every prefix subarray
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (pref[r + 1] - pref[l] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
