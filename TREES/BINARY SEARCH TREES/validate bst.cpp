https://leetcode.com/problems/validate-binary-search-tree/description/


class Solution {
public:
    bool ans = true;                    // To keep track if the tree is a valid BST
    long long last = LONG_MIN;         // To store the value of the last visited node

    void helper(TreeNode* root) {
        if (root == NULL || !ans) return;

        helper(root->left);            // Visit left subtree

        if (root->val <= last) {       // Not strictly increasing → invalid BST
            ans = false;
            return;
        }

        last = root->val;              // Update last to current node’s value

        helper(root->right);           // Visit right subtree
    }

    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
