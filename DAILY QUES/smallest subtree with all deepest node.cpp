https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-06-06


class Solution {
public:
    unordered_map<TreeNode*, int> depthMap; //store depth
    int maxDepth = 0;

    void findDepth(TreeNode* root, int depth) {
        if (!root) return;

        depthMap[root] = depth;
        maxDepth = max(maxDepth, depth);

        findDepth(root->left, depth + 1);
        findDepth(root->right, depth + 1);
    }

    TreeNode* findLCA(TreeNode* root) {
        if (!root || depthMap[root] == maxDepth) {
            return root;
        }
        TreeNode* left = findLCA(root->left);
        TreeNode* right = findLCA(root->right);

        if (left && right) {
            return root;
        }
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        findDepth(root, 0);
        return findLCA(root);
    }
};
