https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& candidates, int target,vector<int>temp,int i){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],temp,i);
        temp.pop_back();
        solve(candidates,target,temp,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates,target,temp,0);
        return result;
        
    }
};
