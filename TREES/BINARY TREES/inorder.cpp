https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1714566186/


class Solution {
public:
    void solver(TreeNode*root,vector<int>&result){
        if(root==NULL){
            return;
        }
        solver(root->left,result);
        result.push_back(root->val);
        solver(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        solver(root,result);
        return result;
    }
};
