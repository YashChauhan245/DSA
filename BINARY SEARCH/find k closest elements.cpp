https://leetcode.com/problems/find-k-closest-elements/?source=submission-ac

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // Search range for starting index of window
        int left = 0;
        int right = n - k;  // window of size k must fit

        // Binary search to find best window start
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare which side is closer to x
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Return k closest elements from the window [left, left+k)
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
