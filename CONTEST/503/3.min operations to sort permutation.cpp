https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/


// Observation:
// A valid permutation can only be:
// 1. Sorted in increasing order:  [0,1,2,3,...,n-1]
// 2. Sorted in decreasing order: [n-1,n-2,...,0]
// 3. A rotated sorted of one of the above.

// Idea:
// Find the position of 0.
// Using position of 0, check whether the array forms
// an increasing cyclic permutation or a decreasing cyclic permutation.

// For increasing order:
// Starting from index 'pos' (where 0 is present),
// elements should appear as:
// 0,1,2,3,...,n-1

// For decreasing order:
// Consecutive elements should differ by -1 modulo n.

// If the permutation is valid, compute the minimum number
// of operations needed to bring it to the required form.
// Take the minimum among all possible valid operations.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int pos = 0, ans = INT_MAX;

        // Find the position of 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                pos = i;
            }
        }

        int n = nums.size();

        // Check if array is a rotation of increasing order
        bool inc = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                inc = false;
                break;
            }
        }

        if (inc) {
            // Move 0 to front using left/right rotations
            int op1 = pos;
            int op2 = n - pos + 2;

            ans = min({ans, op1, op2});
        }

        // Check if array is a rotation of decreasing order
        bool dec = true;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int nxt = nums[(i + 1) % n];

            // Difference should be -1 modulo n
            if ((nxt - curr + n) % n != n - 1) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int k = n - 1 - pos;

            // operation converting decreasing rotation
            int op1 = k + 1;
            int op2 = n - k + 1;
            ans = min({ans, op1, op2});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
