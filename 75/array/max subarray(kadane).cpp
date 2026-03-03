https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int sum=0;
        int maxy=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum>maxy){
                maxy=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxy;

    }
};
