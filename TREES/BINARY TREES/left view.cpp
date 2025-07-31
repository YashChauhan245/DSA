https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution {
  public:
  
    void solver(Node*root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solver(root->left,ans,level+1);
        solver(root->right,ans,level+1);
    }
    vector<int> leftView(Node *root) {
        vector<int>ans;
        int level=0;
        solver(root,ans,level);
        return ans;
        
    }
};

