https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/

// Approach-1 (Using 2 Pass Solution and LCA code)
// T.C : O(2 * n) ~= O(n)
// S.C : O(maxDepth) - System stack space

class Solution {
public:
    unordered_map<int, int> mp; //store depth
    int maxD = 0;

    TreeNode* LCA(TreeNode* root) {
        if (root == nullptr || mp[root->val] == maxD) {
            return root;
        }
        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if (left && right) {
            return root;
        }
        return left ? left : right;
    }

    void depth(TreeNode* root, int d) {
        if (!root) {
            return;
        }

        maxD = max(maxD, d);
        mp[root->val] = d;

        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }

    // T.C : O(n)
    // S.C : O(maxDepth) - Recursion stack space
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};
