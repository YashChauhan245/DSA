https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/description/


/*
add window 
pre compute prime factor of all num
maintain freq of all prime factors
add distint num in another freq
if distinct>0--->remove factors 
if distinct <=k -->update 
*/

class Solution {
public:
    vector<int>getPrimeFactors(int x){
        vector<int>factors;

        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                factors.push_back(i);
                while(x%i==0){
                    x=x/i;
                }
            }
        }
        if(x>1){
            factors.push_back(x);
        }
        return factors;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>factors(n);
        //pre compute all primem factors
        for(int i=0;i<n;i++){
            factors[i]=getPrimeFactors(nums[i]);
        }

        unordered_map<int,int>freq;
        int left=0;
        int distinct=0;
        int ans=0;
        for(int right=0;right<n;right++){
            for(int f :factors[right]){
                if(freq[f]==0){
                    distinct++;
                }
                freq[f]++;
            }
            while(distinct >k){
                for(int f:factors[left]){
                    freq[f]--;
                    if(freq[f]==0){
                        distinct --;
                    }
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
