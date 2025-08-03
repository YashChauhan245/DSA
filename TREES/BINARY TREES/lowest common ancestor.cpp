https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

OPTIMAL: 0(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
       //root hi lca hua to ...
        if (root == p || root == q)
            return root;
       //left and right side seach kra
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
      
      // if left and right dono se ans aa gya 
        if (left != NULL && right != NULL)
            return root;
       //sirf left se aaya ya sirf right se aaya
        if (left != NULL)
            return left;
        else
            return right;
    }
};
