https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        long long maxw=0;

        q.push({root,0});
        while(!q.empty()){
            long long n=q.size();
            long long l=q.front().second;//leftmost 
            long long r=q.back().second;//rightmost
            maxw=max(maxw,r-l+1);
            while(n--){//works same as null in level order ...helps to separate levels
                // now we have to pop and access its child 
                TreeNode*front=q.front().first;
                long long index=q.front().second;
                q.pop();
                if(front->left!=NULL){
                    q.push({front->left,2*index+1});
                }
                if(front->right!=NULL){
                    q.push({front->right,2*index+2});
                }
            }
        } 
        return maxw;   
    }
};
