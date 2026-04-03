https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minhp;//lowest freq element at top
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        } 
      
        for (auto it : freq) {
            minhp.push({it.second, it.first});
            if(minhp.size()>k){
                minhp.pop();
            }
        }
        while(!minhp.empty()){
            ans.push_back(minhp.top().second);
            minhp.pop();
        }
        return ans;
    }
};
