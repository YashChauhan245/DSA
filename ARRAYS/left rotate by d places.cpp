// LEETCODE-https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
//     void reverse(vector<int>& nums) {
//     int left = 0, right = nums.size() - 1;
//     while (left < right) {
//         swap(nums[left++], nums[right--]);
//     }
// }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // Handle k > n
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }

    }
};
