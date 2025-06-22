//Leetcode-https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int xor2=0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];    // XOR of array
            xor2 ^= i;          // XOR of 0 to n-1
        }
        xor2 ^= n;              // XOR with n
        return xor1 ^ xor2;
    }
};
