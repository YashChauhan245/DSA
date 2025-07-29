https://leetcode.com/problems/balanced-binary-tree/description/

APPROACH--1) o(N2)

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right)) {
            return true;
        }

        return false;
    }
};



APPROACH-2)O(N)
class Solution {
public:
    // Returns height if balanced, else -1
    int check(TreeNode* root) {
        if (root == NULL) return 0;

        int left = check(root->left);
        if (left == -1) return -1; // Left not balanced

        int right = check(root->right);
        if (right == -1) return -1; // Right not balanced
        
        if (abs(left - right) > 1) return -1; // This node not balanced
        return 1 + max(left, right); // Return height
    }

    bool isBalanced(TreeNode* root) {
        int result = check(root);
        if (result == -1) {
            return false;  // tree is unbalanced
        } else {
            return true;   // tree is balanced
        }
    }
};
