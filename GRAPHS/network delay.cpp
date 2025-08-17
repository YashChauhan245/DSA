https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);//as indexing are from 1
        for(auto &time:times){
            int u=time[0];
            int v=time[1];
            int wt=time[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            //pop se baad ab src se kha ja sktaa hu 
            for(auto &it:adj[node]){
                //{v,w} -->w is 2 and v is 1
                int adjnode = it.first;
                int edgewt = it.second;
                //if parent dist+curr node dist is smaller
                if(dis+edgewt<dist[adjnode]){
                    dist[adjnode]=dis+edgewt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<dist.size();i++){
            ans=max(ans,dist[i]);
        }  
        if(ans==INT_MAX){
            return -1;
        } 
        else{
            return ans;
        }  
    }
};
