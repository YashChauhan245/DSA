https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftans=maxDepth(root->left);
        int rightans=maxDepth(root->right);
        int maxans=max(leftans,rightans);
        int totaldepth=maxans+1;
        return totaldepth;
        
    }
};
