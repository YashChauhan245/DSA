https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            
            // if mid is target
            if (nums[mid] == target)
                return true;


            // handle duplicates
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            }
            //find the sorted part 
            else if(nums[s]<=nums[mid]){
                // left sorted
                if(target>=nums[s] && target<nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                //right sorted
                if(target>nums[mid] && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return false;
    }
};
