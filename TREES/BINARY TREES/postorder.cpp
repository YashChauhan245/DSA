https://leetcode.com/problems/binary-tree-postorder-traversal/


APPROACH-1)RECURSIVE
class Solution {
public:
    void solver(TreeNode*root,vector<int>&result){
        if(root==NULL){
            return;
        }
        solver(root->left,result);
        solver(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        solver(root,result);
        return result;
    }
};


APPROACH-2)ITERATIVE(USING 1 STACK)

class Solution {
public:
    void solver(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        TreeNode* curr = root;
        TreeNode* temp = nullptr;
        stack<TreeNode*> st;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solver(root, ans);
        return ans;
    }
};
