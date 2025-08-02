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
                pre = curr->left;//left child not null hau 
                // to uske rghmost pe jao 
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                //rightmost full aa gya 
                // isse main root(curr) se connect kryo
                pre->right = curr;
                TreeNode* temp = curr;
                //curr ko left child pe bhejyo and link ko destroy kro
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};
