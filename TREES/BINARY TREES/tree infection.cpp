https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

class Solution {
public:

    // STEP1->maping child and parent
    unordered_map<TreeNode*,TreeNode*>parent;//child,parent
    TreeNode*targetnode=NULL;
    void addparentandfindtarget(TreeNode*root,int start){
        if(root==NULL){
            return;
        }
        // finding target
        if(root->val==start){
            targetnode=root;
        }
        //maping left and right child with its parent
        if(root->left!=NULL){
            parent[root->left]=root;
            addparentandfindtarget(root->left,start);
        }
        if(root->right!=NULL){
            parent[root->right]=root;
            addparentandfindtarget(root->right,start);
        }
    }

    // STEP-2>process of infecting nodes and time calc
    int infected(TreeNode*targetnode){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(targetnode);
        visited.insert(targetnode);
        int time=0;
        while(!q.empty()){
            int n=q.size();
            bool anyinfect=false;
            while(n--){
                TreeNode*front=q.front();
                q.pop();
                if(front->left !=NULL && !visited.count(front->left)){
                    q.push(front->left);
                    visited.insert(front->left);
                    anyinfect=true;
                }
                if(front->right!=NULL && !visited.count(front->right)){
                    q.push(front->right);
                    visited.insert(front->right);
                    anyinfect=true;
                }
                // parent ka front exist krta hai && vo visited me nhi hai 
// if (parent.find(front) != parent.end() && visited.find(parent[front]) == visited.end())
                if(parent.count(front) && !visited.count(parent[front])){
                    q.push(parent[front]);
                    visited.insert(parent[front]);
                    anyinfect=true;
                }

            }
            if (anyinfect)time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        addparentandfindtarget(root,start);
        return infected(targetnode);
    }
};
