https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


class Solution {
public:
    void solver(TreeNode*root ,vector<vector<int>>&result){
        int level=-1;
        vector<int>path;
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
                level++;
                if(level &1){
                    reverse(path.begin(),path.end());
                    result.push_back(path);
                    path.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    result.push_back(path);
                    path.clear();
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }

            }
            else{
                path.push_back(front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        solver(root,result);
        return result;
    }
};
