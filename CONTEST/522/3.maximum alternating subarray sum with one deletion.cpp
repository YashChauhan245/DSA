https://leetcode.com/problems/maximum-alternating-subarray-sum-with-one-deletion/description/



class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long neg=-1e18;
        long long even0=neg;
        long long odd0=neg;

        long long even1=neg;
        long long odd1=neg;
        long long ans=neg;

        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            long long oldEven0=even0;
            long long oldEven1=even1;
            long long oldOdd0=odd0;
            long long oldOdd1=odd1;

            even0=max(x,oldOdd0+x);
            odd0=oldEven0-x;

            even1=neg;
            odd1=neg;

            if(i>0){
                even1=max(even1,x);
            }

            even1=max(even1,oldOdd1+x);
            odd1=max(odd1,oldEven1-x);

            even1=max(even1,oldEven0);
            odd1=max(odd1,oldOdd0);

            ans=max(ans,even0);
            ans=max(ans,odd0);
            ans=max(ans,even1);
            ans=max(ans,odd1);
        }
        return ans;
    }
};
