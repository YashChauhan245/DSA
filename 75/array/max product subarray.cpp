https://leetcode.com/problems/maximum-product-subarray/description/


complexity-->o(n) and 0(1)
  
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int onecase = nums[i];
            int twocase = nums[i] * minprod;
            int threecase = nums[i] * maxprod;

            //finding max
            int newmaxprod = max(onecase, max(twocase, threecase));
            int newminprod = min(onecase, min(twocase, threecase));
            
            //updating
            maxprod = newmaxprod;
            minprod = newminprod;

            ans = max(ans, maxprod);
        }

        return ans;
    }
};
