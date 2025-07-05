https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    bool ans=false;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (nums[mid] == target){
            ans=true;
        }
        // Handle duplicates
        if (nums[s] == nums[mid] && nums[e] == nums[mid]) {
            s++;
            e--;
            continue;
        }

        // Left half is sorted
        if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return ans;
        
    }
};
