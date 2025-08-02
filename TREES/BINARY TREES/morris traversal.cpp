https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) { //no more left
                result.push_back(curr->val);//print root
                curr = curr->right;//iterate to rigth child
            } else {
                pre = curr->left;//if left child hai -->to iterate kro left me hi
                
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};
