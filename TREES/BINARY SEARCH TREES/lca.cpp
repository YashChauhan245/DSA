https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        // If root is p or q, return root
        if(root == p || root == q) {
            return root;
        }

        // If p and q are on opposite sides
        if((p->val > root->val && q->val < root->val) || 
           (p->val < root->val && q->val > root->val)) {
            return root;
        }

        // Both nodes on right
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Both nodes on left
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root; // Just in case (should not reach here)
    }
};
