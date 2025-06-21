//Leetcode-https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxy=INT_MIN;
        int n=nums.size();
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }
            else{
                maxy=max(maxy,one);
                one=0;
            }
        }
        // int MAX_CONS=max(one,max);
        return max(one,maxy);
    }
};
