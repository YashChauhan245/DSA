https://leetcode.com/problems/path-sum/submissions/1716106495/

class Solution {
public:
    bool solve(TreeNode* root, int target, int sum){
        if(root == NULL) return false;
        // ab root pakka non null hai
        sum = sum + root->val;
        if(root->left == NULL && root->right == NULL){
            // root is leaf node
            if(sum == target) return true;
            else return false;
        }
        bool leftAns = solve(root->left,target,sum);
        bool rightAns = solve(root->right,target,sum);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root,targetSum,sum);
        return ans;
    }
};
