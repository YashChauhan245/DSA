https://leetcode.com/problems/shortest-path-with-alternating-colors/description/?envType=study-plan-v2&envId=graph-theory


class Solution { 
public: 
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,vector<vector<int>>& blueEdges) { 
        vector<vector<pair<int, int>>> graph(n); 
        int RED = 0; 
        int BLUE = 1; 
 
        for (auto edge : redEdges) { 
            int u = edge[0]; 
            int v = edge[1]; 
            graph[u].push_back({v, RED}); 
        } 
 
        for (auto edge : blueEdges) { 
            int u = edge[0]; 
            int v = edge[1]; 
            graph[u].push_back({v, BLUE}); 
        } 
 
        vector<int> answer(n, -1); 
        answer[0] = 0; 
 
        vector<vector<bool>> visited(n, vector<bool>(2, false)); 
 
        // node, lastColor, distance
        queue<tuple<int, int, int>> q; 
        
        q.push({0, RED, 0}); 
        q.push({0, BLUE, 0}); 
 
        while (!q.empty()) { 
            auto [node, lastColor, dist] = q.front(); 
            q.pop(); 
 
            int nextColor = 1 - lastColor; 
 
            for (auto [neighbor, color] : graph[node]) { 
 
                // We need alternating colors
                if (color != nextColor) 
                    continue; 
 
                // Already visited this state
                if (visited[neighbor][color]) 
                    continue; 
 
                visited[neighbor][color] = true; 
 
                // Distance of THIS state
                if (answer[neighbor] == -1) { 
                    answer[neighbor] = dist + 1; //uodate distance 
                } 
 
                q.push({neighbor, color, dist + 1}); 
            } 
        } 
 
        return answer; 
    } 
};
