//https://leetcode.com/problems/next-permutation/submissions/1673615321/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {

// Brute force-->find all permutations using recursion ,then linear search array and find next permutation using index+1...

// Better-->using STL-- next permutation(nums.begin(),nums.end())...

// Optimised:
        int ind=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return ;//Edge case
        }

        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};                           
