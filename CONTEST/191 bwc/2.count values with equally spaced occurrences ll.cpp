https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/


class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;

        for(auto &p:mp){
            vector<int>&v=p.second;

            if(v.size()<3){
                continue;
            }
            int diff=v[1]-v[0];
            bool special=true;

            for(int i=2;i<v.size();i++){
                if(v[i]-v[i-1]!=diff){
                    special=false;
                    break;
                }
            }
            if(special==true){
                ans++;
            }
        }
        return ans;
    }
    
};
