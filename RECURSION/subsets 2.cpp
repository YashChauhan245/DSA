https://leetcode.com/problems/subsets-ii/description/


class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums,vector<int>temp,int i){
        // no proper base case as want all subsets including empty set
        result.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,temp,j+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,temp,0);
        return result;

    }
};

// **TREE**

solve(i=0, temp=[])                          // push []
 ├── j=0 → temp=[1]
 │    solve(i=1, temp=[1])                   // push [1]
 │     └── j=1 → temp=[2]
 │          solve(i=2, temp=[1,2])           // push [1,2]
 │           └── j=2 → temp=[1,2,2]
 │                solve(i=3, temp=[1,2,2])   // push [1,2,2]
 │                (return)
 │          (backtrack to temp=[1,2])
 │          j=2 is **skipped** (duplicate at same depth: j>i && 2==2)
 │    (return)
 ├── j=1 → temp=[2]
 │    solve(i=2, temp=[2])                   // push [2]
 │     └── j=2 → temp=[2,2]
 │          solve(i=3, temp=[2,2])           // push [2,2]
 │          (return)
 │    (return)
 └── j=2 is **skipped** (duplicate at same depth: j>0 && 2==2)

(return)

