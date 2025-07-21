https://leetcode.com/problems/find-k-closest-elements/description/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>>maxhp;
        for(int i=0;i<arr.size();i++){
            int diff=abs(arr[i]-x);
            maxhp.push({diff,arr[i]});
            if(maxhp.size()>k){
                maxhp.pop();
            }
        }
        while(!maxhp.empty()){
            ans.push_back(maxhp.top().second);
            maxhp.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
