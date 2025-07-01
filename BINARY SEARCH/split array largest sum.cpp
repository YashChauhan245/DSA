class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSumAllowed, int k) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currentSum + nums[i] > maxSumAllowed) {
                subarrayCount++;
                currentSum = 0;
            }
            currentSum += nums[i];
        }

        return subarrayCount <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int s =*max_element(nums.begin(), nums.end());
        int e =accumulate(nums.begin(), nums.end(), 0);
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (canSplit(nums, mid, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
