https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minhp;
        for(int i=0;i<nums.size();i++){
            minhp.push(nums[i]);
            if(minhp.size()>k){
                minhp.pop();
            }
        }
       return minhp.top(); 
    }
};
