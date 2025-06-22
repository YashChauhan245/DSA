//https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int>pos;
    //     vector<int>neg;
    //     vector<int>ans;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]>0){
    //             pos.push_back(nums[i]);
    //         }
    //         else{
    //             neg.push_back(nums[i]);
    //         }
    //     }
    //     for(int i=0;i<pos.size();i++){
    //         ans.push_back(pos[i]);
    //         ans.push_back(neg[i]);
    //     }
    // return ans;

        vector<int>ans(nums.size());
        int posindex=0;
        int negindex=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
            ans[posindex]=nums[i];
            posindex+=2;
            }
            else{
            ans[negindex]=nums[i];
            negindex+=2;
            }
        }
        return ans;
 
    }
};
