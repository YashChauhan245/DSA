https://leetcode.com/problems/max-consecutive-ones-iii/description/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int len=0;
        int zero=0;
        int n=nums.size();

        while(r<n){
            //step-2...if num[r]==0-->zero++ 
            if(nums[r]==0){
                zero++;
            }
            //step-3....if zero<=k --->calc length
            if(zero<=k){
                len=r-l+1;
                maxlen=max(maxlen,len);
            }
            //step-4...if zero>k-->update l
            while(zero>k){
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            //step-1...if nums[r]==1
            r++;
        }
        return maxlen;
    }
};
