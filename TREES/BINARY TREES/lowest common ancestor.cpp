https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

BRUTE FORCE : O(3N)
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL){
            return false;
        }
        path.push_back(root);

        if (root == target){
            return true;
        }
        // Search in left or right subtree
        if (findPath(root->left, target, path) || findPath(root->right, target, path)){
            return true;
        }

        path.pop_back();  // backtrack
        return false;
    }



OPTIMAL: 0(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
       //root hi lca hua to ...
        if (root == p || root == q)
            return root;

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




OPTIMAL ->
