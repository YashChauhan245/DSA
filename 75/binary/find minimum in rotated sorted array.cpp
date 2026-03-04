https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/


brute->o(n) and o(1)

class Solution {
public:

    int findMin(vector<int>& nums) {
        int minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
        }
        return minVal;
    }
};



optimal ->o(logn)
  
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){//case=[4,5,6,7,0,1,2]
                s=mid+1;
            }
            else{
                e=mid ;//case=[5,6,0,1,2,3,4]
            }
        }
        return nums[s];
    }
};
