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
    // making node*front which store front and helps in the access of left and right tree
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
                //if q is not empty after level 1 i.e more levels  sre there
                //[2,3] is still there as after poping 1, child is inserted
                //so push null after there child ...new queue =[2,3,null]
                    q.push(NULL);
                }
            } else {
            //if front is 2 ....push in level 
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




**DRY RUN **

        1
       / \
      2   3
     /   / \
    4   5   6
q: [1, NULL]
level: []
result: []


  | Action                | Queue            | Level      | Result                       |
| --------------------- | ---------------- | ---------- | ---------------------------- |
| pop 1, push 2 & 3     | \[NULL, 2, 3]    | \[1]       | \[]                          |
| pop NULL → level done | \[2, 3]          | \[]        | \[\[1]]                      |
| push NULL             | \[2, 3, NULL]    | \[]        | \[\[1]]                      |
| pop 2, push 4         | \[3, NULL, 4]    | \[2]       | \[\[1]]                      |
| pop 3, push 5 & 6     | \[NULL, 4, 5, 6] | \[2, 3]    | \[\[1]]                      |
| pop NULL → level done | \[4, 5, 6]       | \[]        | \[\[1], \[2, 3]]             |
| push NULL             | \[4, 5, 6, NULL] | \[]        | \[\[1], \[2, 3]]             |
| pop 4 (no children)   | \[5, 6, NULL]    | \[4]       | \[\[1], \[2, 3]]             |
| pop 5 (no children)   | \[6, NULL]       | \[4, 5]    | \[\[1], \[2, 3]]             |
| pop 6 (no children)   | \[NULL]          | \[4, 5, 6] | \[\[1], \[2, 3]]             |
| pop NULL → level done | \[]              | \[]        | \[\[1], \[2, 3], \[4, 5, 6]] |
