https://leetcode.com/problems/binary-tree-maximum-path-sum/


class Solution {
public:
    int maxsum;
    int solver(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left=solver(root->left);
        int right=solver(root->right);

        // now cases

        // niche hi max mil gyaa but main root ko include nhi kr payege bcz of path ...3d path bn jayega warna 
        int noreturn=left+right+root->val;
        //1 if left ya right me se koi ek ho
        int onlyone=max(left,right)+root->val;
        // root khud hi max ho
        int rootmax=root->val;
        maxsum=max({maxsum,noreturn,onlyone,rootmax});
        // imp as we can only return these two ;
        return max(onlyone,rootmax);
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solver(root);
        return maxsum;
    }
};
