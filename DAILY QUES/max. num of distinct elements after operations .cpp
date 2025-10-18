https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/submissions/1805006219/

//sort-->nums[i-k] -->if already present then prev+1 but but prev+1 >limit(nums[i]-k,nums[i]+1) -->return k
//e.g -->[4,4,4,4] k=1-->so limit is [4-1;4+1]=[3,5] So, output=[3,4,5,4]



class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int count = 0;

        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if(prev < minVal) {
                //nums[i] = nums[i]-k;
                prev = minVal;
                count++;
            } else if(prev < nums[i] + k) {
                //nums[i] = prev+1;
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};
