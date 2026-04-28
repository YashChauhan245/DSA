https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/


/**
 approach 1-->go to each node and check that nodes is a validate bst or not (tc-o(n2))
 approach 2-->check bst only for left subtree  right subtree and then check 
 maxleft<root<minright--->balanced tree apporach  
 */
class Solution {
public:
    
    class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int sum;   
    };

    info solve(TreeNode* root, int &ans) {
        if (root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info currNode;

        currNode.sum = left.sum + right.sum + root->val;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);

        if (left.isBST && right.isBST &&
            (root->val > left.maxi && root->val < right.mini)) {
            
            currNode.isBST = true;
            //update ans
            ans = max(ans, currNode.sum);
        } 
        else {
            currNode.isBST = false;
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
