https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX); 
    }

    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        // Left subtree bound = root->val
        root->left = helper(preorder, i, root->val);

        // Right subtree bound = parent's bound
        root->right = helper(preorder, i, bound);

        return root;
    }
};
