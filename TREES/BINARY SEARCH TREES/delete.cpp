https://leetcode.com/problems/delete-node-in-a-bst/description/


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            // match

            // with 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // with left child only
            if(root->left != NULL && root->right == NULL){
                TreeNode* leftChild = root->left;
                root->left = NULL;
                delete root;
                return leftChild;
            }

            // with right child only
            if(root->left == NULL && root->right != NULL){
                TreeNode* rightChild = root->right;
                root->right = NULL;
                delete root;
                return rightChild;
            }

            // has both left and right child
            if(root->left != NULL && root->right != NULL){
                // find just chota element
                int maxVal = getMax(root->left);
                // replace node to be deleted value with maxVal
                root->val = maxVal;
                // delete actual node of maxVal
                root->left = deleteNode(root->left, maxVal);
                return root;

                // OR find just bada element
                // int minVal = getMin(root->right);
                // root->val = minVal;
                // root->right = deleteNode(root->right,minVal);
                // return root;
            }
        }
        else{
            // not match
            // go left or right
            if(key < root->val){
                // left
                root->left = deleteNode(root->left,key);
            }
            else{
                // right 
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }

    int getMax(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }

    // Optional: if using inorder successor instead
    // int getMin(TreeNode* root) {
    //     while (root->left != NULL) {
    //         root = root->left;
    //     }
    //     return root->val;
    // }
};
