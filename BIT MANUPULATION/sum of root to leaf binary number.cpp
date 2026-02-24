https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24

//Approach - Recursion
//T.C : O(n)
//S.C : O(1) Auxiliary space (But O(n) system recursion stack space)
class Solution {
public:
    int solve(TreeNode* root, int val) {
        if(!root) { //root == NULL
            return 0;
        }

        val = (2*val) + root->val;

        if(root->left == NULL && root->right == NULL)
            return val;
        
        return solve(root->left, val) + solve(root->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};
