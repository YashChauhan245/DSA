https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public:
    void solver(TreeNode* root,vector<int>&ans){
        if(root==nullptr){
            return ;
        }
        // push root in answer
        ans.push_back(root->val);
        // left recur
        solver(root->left,ans);
        // right recur
        solver(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solver(root,ans);
        return ans;          
    }
};
