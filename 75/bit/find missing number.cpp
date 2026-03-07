https://www.geeksforgeeks.org/dsa/find-the-missing-number/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;

        int sum = 0;
        for(int num : nums)
            sum += num;

        return expected - sum;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for(int i = 0; i < n; i++){
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};]
