https://leetcode.com/problems/maximum-depth-of-binary-tree/

APPROACH-1)using iterative way 

class Solution {
public:

    void solver(TreeNode*root,int &length){
        queue<TreeNode*>q;
        if(root==NULL){
            return;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front==NULL){
                length++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
        
    }
    int maxDepth(TreeNode* root) {
        int length=0;
        solver(root,length);
        return length;
        
    }
};


APPROACH-2)USING RECURSION

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftans=maxDepth(root->left);
        int rightans=maxDepth(root->right);
        int maxans=max(leftans,rightans);
        int totaldepth=maxans+1;//+1 bcz if there is no child ..only root present so height is 1;
        return totaldepth;
        
    }
};
