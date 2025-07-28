https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    void solver(TreeNode*root,vector<int>&result){
        if(root==NULL){
            return;
        }
        solver(root->left,result);
        solver(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        solver(root,result);
        return result;
    }
};
