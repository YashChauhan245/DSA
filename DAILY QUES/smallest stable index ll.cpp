https://leetcode.com/problems/smallest-stable-index-ii/description/?envType=daily-question&envId=2026-09-05


class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        //prefix array 
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>prefix[i-1]){
                prefix[i]=nums[i];
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }

        //suffix array 
        vector<int>suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<suffix[i+1]){
                suffix[i]=nums[i];
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }
        
        for(int i=0;i<n;i++){
            if(prefix[i]-suffix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};
