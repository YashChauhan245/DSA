https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1


class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        queue<Node*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            Node*front=q.front();
            q.pop();
            while(front!=NULL){
                // if node ka left hai to queue me dalo
                if(front->left){
                    q.push(front->left);
                }
                // else usse ans me store kro and iterate krdo right child ki trh 
                ans.push_back(front->data);
                // right child iterate
                front=front->right;
            }
            
        }
        return ans;
        
    }
};
