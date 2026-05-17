

//Apporach-->binary search+ hash --->TLE
class Solution {
public:

    bool check(int len, vector<int>& nums) {
        map<vector<int>, int> mp;// stores subarr -> frequency
        int n = nums.size();

        //generate all subarr of size len
        for (int i = 0; i + len <= n; i++) {
            vector<int> temp;
            for (int j = i; j < i + len; j++) {//build current subar
                temp.push_back(nums[j]);
            }
            mp[temp]++;
        }

        // unique subarray exists
        for (auto it : mp) {
            if (it.second == 1)
                return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


//OPTIMAL --->USE ROLLING HASH OR KMP
