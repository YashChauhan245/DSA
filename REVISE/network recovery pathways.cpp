https://leetcode.com/problems/network-recovery-pathways/description/?envType=daily-question&envId=2026-07-03



/*
APPROACH:
1. I apply binary search on the possible score range 
(low = 0, high = maximum edge weight).

2.I calculate mid, suppose mid = 3, meaning I want a path where every
edge has weight at least 3.

3.Now I run Dijkstra. While exploring paths, if an edge weight is less
than mid, I skip that edge. Otherwise, I use that edge and continue
finding the shortest path.

4.After Dijkstra finishes, I check the shortest cost to reach the final
node. If the cost is <= k, then this mid is a valid answer, so I store
ans = mid and search for a bigger score using low = mid + 1.

5.If Dijkstra cannot reach the final node within k, mid is too large,
so I reduce the search space using high = mid - 1.
*/

class Solution {
public:
    typedef pair<long long, int> P;
    typedef long long ll;

	bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int>>>& adj) {
        vector<ll> result(n, LLONG_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        result[0] = 0;

        pq.push({0, 0});

        while(!pq.empty()) {
            ll d     = pq.top().first; //dist/cost
            int node = pq.top().second;
            pq.pop();

            if(d > k) 
                return false;

            if(node == n - 1) 
                return true;

            if(d > result[node]) 
                continue;

            for(auto &vec : adj[node]) {
                int adjNode  = vec[0];
                int edgeCost = vec[1];

                if(edgeCost < mid)  //dont explore path if node < mid
                    continue;

                if(d + edgeCost < result[adjNode]) {
                    result[adjNode] = d + edgeCost;
                    pq.push({d + edgeCost, adjNode});
                }
            }
        }

        return false;
	}

	int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, ll k) {
		int n = online.size();
        unordered_map<int, vector<vector<int>>> adj;

		int l = INT_MAX, r = 0;

		for(auto &edge : edges) {
		    int u = edge[0];
		    int v = edge[1];
		    int w = edge[2];
            
            //if node offline
		    if(!online[u] || !online[v]) 
                continue;
                
		    adj[u].push_back({v, w});
		    l = min(l, w);
		    r = max(r, w);
		}

        int answer = -1;
        

        //binary search 
		while(l <= r) {
		    int mid = l + (r - l) / 2;

		    if(check(mid, n, k, adj)) {  //check valid path using dijkstra
                answer = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
		}

		return answer;
	}
};
