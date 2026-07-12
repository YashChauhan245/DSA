https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;
        mp[0] = -1;   // Prefix sum 0 before array starts

        long long prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            // If (prefix - k) exists, subarray present 
            if (mp.find(prefix - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefix - k]);
            }

            //store first occurrence of every prefix sum
            if (mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
        }

        return maxLen;
    }
};
