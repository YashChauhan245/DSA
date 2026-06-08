https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;
        int j=n-1;
        int left=0;
        int right=n-1;

        while(i<n){
            if(nums[i]<pivot){
                ans[left]=nums[i];
                left++;
            }

            if(nums[j]>pivot){
                ans[right]=nums[j];
                right--;
            } 
            i++;
            j--;
        }
        //remaining indices will be filled with pivot
        while (left <= right) {
            ans[left++] = pivot;
        }
        
        return ans;
    }
};
