https://leetcode.com/problems/3sum/

//T.C : O(n^2)
//S.C : O(1)

// steps: 1)sort 2)n2+n3=-n1 && before fixing n1 check duplicates too 3)remove duplicates in 2sum 
class Solution {
public:
 
    void twoSum(vector<int>& nums, int k, vector<vector<int>>& result, int target) {       
        int i = k, j = nums.size()-1;
        while(i < j) {
            if(nums[i]+nums[j] > target)
                j--;
            else if(nums[i] + nums[j] < target)
                i++;
            else {
                result.push_back({-target, nums[i], nums[j]});
                // avoid duplicate
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                //result/target find ..so iterate for next result
                i++;
                j--; 
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        //edge case
        if(n<3){
            return {};
        }
        // sort
        sort(begin(nums),end(nums));

        // fixing one element -->n1
        for(int i=0;i<n;i++){
            //check duplicate
            if(i!= 0 && nums[i] == nums[i-1]) { 
                continue;
            }

            twoSum(nums, i+1, result, -nums[i]);//arr,k,result,target
        }
        return result;
    }
};
