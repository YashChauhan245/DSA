https://leetcode.com/problems/merge-intervals/submissions/1674857504/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int>&curr=intervals[i];
            vector<int>&prev=ans.back();
            if(curr[0]<=prev[1]){
                prev[1]=max(curr[1],prev[1]);
            }
            else{
                ans.push_back(curr);
            }
        }
        return ans;   
    }
};
