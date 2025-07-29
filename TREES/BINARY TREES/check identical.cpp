https://leetcode.com/problems/same-tree/

class Solution {
public: 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        // root checking
        if (p->val != q->val) {
            return false;
        }
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        // Return true only if both left and right subtrees are same
        return left && right;
    }
};
