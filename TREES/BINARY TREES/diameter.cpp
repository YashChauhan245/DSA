https://leetcode.com/problems/diameter-of-binary-tree/description/


class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update diameter at this node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};
