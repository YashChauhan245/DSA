https://leetcode.com/problems/combination-sum-ii/submissions/1689397794/

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& candidates, int target,vector<int>temp,int idx){
        if(target==0){
            result.push_back(temp);
            return ;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(candidates,target,temp,0);
        return result;
        
    }
};
