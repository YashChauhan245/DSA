https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    void solver(TreeNode* root, vector<vector<int>>& result) {
        if (root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        // for maintaining each level
        vector<int> level;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
    //  initial queue is [1,NULL] -->after poping and printing 1 ->child of 1 [2,3] is pushed in queue now qeueue is [null,2,3]....

    // now front ==null -->so go in next line 
            if (front == NULL) {
                // push elements of one level then clear it for upcoming levels
                result.push_back(level);
                level.clear();
                //null poped
                if (!q.empty()) {
                //[2,3] is still there as after poping 1, child is inserted
                //so push null after there child ...new queue =[2,3,null]
                    q.push(NULL);
                }
            } else {
                level.push_back(front->val);  
                // pushing childs of root 
                if (front->left != NULL) q.push(front->left);
                if (front->right != NULL) q.push(front->right);
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        solver(root, result);
        return result;
    }
};
