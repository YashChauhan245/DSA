https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/description/

class Solution {
public:
    int ans=0;

    int dfs(TreeNode* root){
        if(!root){
            return INT_MIN;
        }
        int left=dfs(root->left);
        int right= dfs(root->right);

        int mx=max(root->val,max(left,right));
        
        if(root->val==mx){
            ans++;
        }
        return mx;
    }
    
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
