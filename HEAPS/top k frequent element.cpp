https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minhp;
        vector<int>ans;
        unordered_map<int,int>freq;
        // storing freq in map
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        // for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
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
