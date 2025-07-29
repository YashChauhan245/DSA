https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    vector<vector<int>> res;

    void solve(TreeNode* root, int targetSum, int sum, vector<int>& path) {
        if (root == NULL) return;

        // Add current node to path and sum
        sum += root->val;
        path.push_back(root->val);

        // Check if it's a leaf node and sum equals targetSum
        if (root->left == NULL && root->right == NULL && sum == targetSum) {
            res.push_back(path);
        }

        // Recurse left and right
        solve(root->left, targetSum, sum, path);
        solve(root->right, targetSum, sum, path);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, 0, path);
        return res;
    }
};
 
