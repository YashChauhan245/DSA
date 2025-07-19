https://leetcode.com/problems/max-consecutive-ones-iii/description/

APPROACH-1)T.C->O(2N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int len=0;
        int mxlen=0;
        int zero=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            if(zero<=k){
                len=r-l+1;
                mxlen=max(mxlen,len);
            }
            r++;
        }
        return mxlen;
    }
};



APPROACH-2)O(N)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int len=0;
        int mxlen=0;
        int zero=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            if(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            if(zero<=k){
                len=r-l+1;
                mxlen=max(mxlen,len);
            }
            r++;
        }
        return mxlen;
    }
};

