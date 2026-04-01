https://leetcode.com/problems/subtree-of-another-tree/description/

class Solution {
public:
    
    bool match(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        if (root->val != subRoot->val) return false;
        
        return match(root->left, subRoot->left) && match(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
       
        //step-1) check if subtree starting at this node matches subRoot
        if (match(root, subRoot)) return true;

        //step-2) if not matched, search in left and right subtrees 
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
