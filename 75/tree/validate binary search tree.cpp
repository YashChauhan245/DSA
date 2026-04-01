https://leetcode.com/problems/validate-binary-search-tree/description/

// RANGE APPROACH -->[MIN,MAX]

class Solution {
public:
    bool solve(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};


//INORDER

class Solution {
public:
    bool ans = true;
    long long last = LONG_MIN;

    void helper(TreeNode* root){
        if(root == NULL) return;

        helper(root->left);

        if(root->val <= last){
            ans = false;
        }

        last = root->val;

        helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)   return true;

        helper(root);

        return ans;
    }
};
