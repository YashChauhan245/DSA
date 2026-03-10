https://leetcode.com/problems/increasing-triplet-subsequence/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int n : nums) {
            if (n <= first) {
                first = n;
            } 
            else if (n <= second) {
                second = n;
            } 
            //greater than both
            else {
                return true;
            }
        }
        return false;
    }
};
