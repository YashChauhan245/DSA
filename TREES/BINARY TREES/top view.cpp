https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        //map storing vertical line and node value 
        map<int,int>mp;
        // queue storing node and vertical line
        queue<pair<Node*,int>>q;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node*node=front.first;
            int vline=front.second;
            //not present in map -->so store it 
            if(mp.find(vline)==mp.end()){

                // vline->node
                mp[vline]=node->data;
            }
            // access of left and right child
            if(node->left!=NULL){
                q.push({node->left,vline-1});
            }
            if(node->right!=NULL){
                q.push({node->right,vline+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
