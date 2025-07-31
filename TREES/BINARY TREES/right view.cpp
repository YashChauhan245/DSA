https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
public:

    void solver(TreeNode*root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        // condn
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        // explore
        solver(root->right,ans,level+1);
        solver(root->left,ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int level=0;
        solver(root,ans,level);
        return ans;
        
    }
};
