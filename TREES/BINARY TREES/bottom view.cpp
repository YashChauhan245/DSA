https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;   //vline and nodes
        // not unordered_map as we want sorted for (-2-->2)
        map<int,int>mp ;   //vline->node->val
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node*nodes=front.first;
            int vline=front.second;
            // top pe check krte the ki present hai ya nhi
            // if not present then push
            // but bottom me push krna hi hai as we want the last node val
            mp[vline]=nodes->data;
            if(nodes->left!=NULL){
                q.push({nodes->left,vline-1});
            }
            if(nodes->right!=NULL){
                q.push({nodes->right,vline+1});
            }
            
        }
        // ITERATIG IN MAP TO STORE ANS
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
