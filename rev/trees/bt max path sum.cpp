https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
        //1st case-->left,right,root path --->but cant return it bcz ans will be change then 
        int noreturn=left+right+root->val;
        //2nd if left ya right me se koi ek ho
        int onlyone=max(left,right)+root->val;
        // 3rdroot khud hi max ho
        int rootmax=root->val;
        maxsum=max({maxsum,noreturn,onlyone,rootmax});
        // imp as we can only return these two and cant return case1 ;
        return max(onlyone,rootmax);
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solver(root);
        return maxsum;
    }
};
