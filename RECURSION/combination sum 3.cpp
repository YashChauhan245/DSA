https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>>result;
    void solve(int k,int n,vector<int>temp,int i){
        // BASE CASE
        if(temp.size()==k){
            if(n==0){
                result.push_back(temp);
                return;
            }
        }
        for(int j=i;j<=9;j++){
            if(j>n){
                break;
            }
            temp.push_back(j);
            solve(k,n-j,temp,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k,n,temp,1);
        return result; 
    }
};
