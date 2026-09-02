https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=problem-list-v2&envId=dlab054g



// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         int n = nums.size();

//         set<int> full(nums.begin(), nums.end());
//         int totalDistinct = full.size();

//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             set<int> current;
//             for (int j = i; j < n; j++) {
//                 current.insert(nums[j]);
//                 if (current.size() == totalDistinct) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        set<int> s(nums.begin(), nums.end());
        int totalDistinct = s.size();

        int ans = 0;

        int l = 0;

        while (l < n) {
            set<int> current;
            int r = l;

            while (r < n) {
                current.insert(nums[r]);

                if (current.size() == totalDistinct) {
                    // Current subarray + all possible extensions
                    ans += n - r;
                    break;
                }

                r++;
            }

            l++;
        }

        return ans;
    }
};
