https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1722956101/


BRTUE->T.C->O(N) AND SC->O(N)

class Solution {
public:
   vector<int>v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i=0;int j=v.size()-1;
        int sum=0;
        while(i<j){
            sum=v[i]+v[j];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }

        }
        return false;
    }
};




OPTIMAL -->TC->O(N) AND SC->O(H)

class Solution {
public:
    stack<TreeNode*> stl;
    stack<TreeNode*> str;

    void insertleft(TreeNode* root) {
        while (root != NULL) {
            stl.push(root);
            root = root->left;
        }
    }

    void insertright(TreeNode* root) {
        while (root != NULL) {
            str.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        insertleft(root);
        insertright(root);

        while (!stl.empty() && !str.empty() && stl.top() != str.top()) {
            int leftVal = stl.top()->val;
            int rightVal = str.top()->val;

            if (leftVal + rightVal == k) {
                return true;
            } else if (leftVal + rightVal < k) {
                TreeNode* node = stl.top();
                stl.pop();
                insertleft(node->right);  // Move left pointer forward
            } else {
                TreeNode* node = str.top();
                str.pop();
                insertright(node->left); // Move right pointer backward
            }
        }

        return false;
    }
};


