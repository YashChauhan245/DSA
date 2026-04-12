https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

//bfs ->just conditon changed !que.empty() && level <= k
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int> &vec : flights) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];     
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que;
        que.push({src, 0});
        distance[src] = 0;
        
        int level = 0;
        
        while(!que.empty() && level <= k) {
            int N = que.size();
            
            while(N--) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();
                
                for(pair<int, int> &P : adj[u]) {
                    
                    int v    = P.first;
                    int cost = P.second;
                    
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        que.push({v, d+cost});
                    }                   
                }                
            }
            level++;
        }   
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};


//djisktra(complex code)
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         unordered_map<int, vector<pair<int,int>>> adj;

//         for (auto &e : flights) {
//             adj[e[0]].push_back({e[1], e[2]});
//         }

//         // {cost, {node, stops}}
//         priority_queue<
//             pair<int, pair<int,int>>,
//             vector<pair<int, pair<int,int>>>,
//             greater<pair<int, pair<int,int>>>
//         > pq;

//         pq.push({0, {src, 0}});

//         vector<int> visited(n, INT_MAX);

//         while (!pq.empty()) {
//             auto top = pq.top();
//             pq.pop();

//             int cost  = top.first;
//             int node  = top.second.first;
//             int stops = top.second.second;

//             if (node == dst) return cost;

//             if (stops > k) continue;
//             if (stops > visited[node]) continue;

//             visited[node] = stops;

//             for (auto &nbr : adj[node]) {
//                 int nei = nbr.first;
//                 int price = nbr.second;

//                 pq.push({cost + price, {nei, stops + 1}});
//             }
//         }

//         return -1;
//     }
// };
