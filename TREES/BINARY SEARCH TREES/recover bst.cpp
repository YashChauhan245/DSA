https://leetcode.com/problems/recover-binary-search-tree/description/

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val > root->val) {
            if (!first) {
                // 1st time wrong 
                first = prev;
                second = root;
            } else {
                //second time wrong
                second = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
