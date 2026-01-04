https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?source=submission-ac


class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else if(nums[mid]==nums[e]){ //ey case use testcase -->[3,3,1,3] && [1,3,3]
                e--;
            }
            else{
                e=mid;
            }
        }
        return nums[s];
    }
};
