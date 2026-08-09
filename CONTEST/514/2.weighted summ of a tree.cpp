https://leetcode.com/problems/weighted-sum-of-a-tree/description/

//build tree from psarents
//calc depth
//fint h=mx depth
//calc nums[i]*(h-depth[i]+1) for every node

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>>adj(n);

        //build tree
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        //depth
        vector<int>depth(n);
        depth[0]=1;

        queue<int>q;
        q.push(0);

        int h=1;

        //find depth

        while(!q.empty()){
            int node=q.front();
            q.pop();
            h=max(h,depth[node]);

            for(int child:adj[node]){
                depth[child]=depth[node]+1;
                q.push(child);
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL * nums[i]*(h-depth[i]+1);
        }
        return ans;   
    }
};
