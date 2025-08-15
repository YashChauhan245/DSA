https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

****USING PQ**** (t.c=O(elogv))
//WILL NOT WORK FOR NEG NODE AND WEIGHT
  class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dist(V,1e9);//1e9->int max 
        dist[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,src});
        
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            //is node se kha kha ja skte hai 
            for(auto &it:adj[node]){
                //{v,w} -->w is 2 and v is 1
                int adjnode = it.first;
                int edgewt = it.second;
                
                if(dis+edgewt<dist[adjnode]){//store in dist vector and min heap
                    dist[adjnode]=dis+edgewt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};




***USING SET***




