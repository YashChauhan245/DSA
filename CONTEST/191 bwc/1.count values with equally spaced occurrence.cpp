https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/description/


class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        int ans=0;
        
        for(auto &p:mp){
            vector<int>v=p.second;
            if(v.size()==3){
                if(v[1]-v[0]==v[2]-v[1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
