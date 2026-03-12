https://leetcode.com/problems/combination-sum/description/

class Solution {
public:

   vector<vector<int>> result;
   void solver(vector<int>& candidates, int target,vector<int>temp,int i){
        //result return case
        if(target==0){
            result.push_back(temp);
            return;
        }

        //edge case
        if(target<0 || i>=candidates.size()){
            return;
        }
        //push ->further check -->popback-->again check with i+1
        temp.push_back(candidates[i]);
        solver(candidates,target-candidates[i],temp,i);
        temp.pop_back();
        solver(candidates,target,temp,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solver(candidates,target,temp,0);
        return result;
    }
};
