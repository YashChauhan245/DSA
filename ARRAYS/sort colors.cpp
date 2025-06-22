// https://leetcode.com/problems/sort-colors/submissions/1672521005/

class Solution {
public:
    void sortColors(vector<int>& nums) {

// Brute force:
        // int zero=0;
        // int one=0;
        // int two=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         zero++;
        //     }
        //     else if(nums[i]==1){
        //         one++;
        //     }
        //     else{
        //         two++;
        //     }
        // }
        // int i=0;
        // while(zero--){
        //     nums[i++]=0;
        // }
        // while(one--){
        //     nums[i++]=1;
        // }
        // while(two--){
        //     nums[i++]=2;
        // }


// OPTIMISED-->dutch flag algo
         int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // NOTE: we do NOT increment mid here
            }
        }

        
    }
};
