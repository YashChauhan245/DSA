https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


class Solution {
public:
    int ans=0;
    void inorder(TreeNode* root, int &k){
        if(root==NULL || k==0){
            return ;
        }
        inorder(root->left,k);
        //go till last left then while returning ->k--
        k--;
        if(k==0){
            ans=root->val;
            return;
        }
        //left me ans nhi mila verna root ke right jate rho
        inorder(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};
