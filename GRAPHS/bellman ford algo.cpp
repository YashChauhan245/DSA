https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

t.c-->o(v*e)//as at worst cases ...we areiterting/relax e edges v-1 time 
s.c-->o(v)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        //now ill iterate for relaxation (V-1) time
        for(int i=0;i<V;i++){
            dist[src]=0;
            //relaxation at all the edges
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 &&dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        } 
        //nth iteration for checking negative cycle
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 &&dist[u]+wt<dist[v]){
                //IF NEW SHORTEST DISTANCE FOUND 
                //RETURN -1
                return {-1};
            }
        }
        return dist;
    }
};
