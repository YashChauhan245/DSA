https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


class Solution {
public:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void addLeftBoundary(Node* node, vector<int>& res) {
        while (node != NULL) {
            if (!isLeaf(node)){
                res.push_back(node->data);
            }
            if (node->left){
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
    }

    void addLeaves(Node* node, vector<int>& res) {
        if (node == NULL) return;
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);//for left leaf -->phele ye run hoga phir print hoga 
      //search yhi kr rhe hai leaf node ko  mainly 
        addLeaves(node->right, res);//for right leaf
    }

    void addRightBoundary(Node* node, vector<int>& res) {
        vector<int> temp;
        while (node != NULL) {
            if (!isLeaf(node)){
                temp.push_back(node->data);
            }
            if (node->right){
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        // reverse before ....bcz while collecting right node ..im going top to bootm ..but i want ans in bootm to top
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (root == NULL) return res;
         //  root added
        if (!isLeaf(root)) res.push_back(root->data);
        // left node
        addLeftBoundary(root->left, res);
        // left and right leaf nodes
        addLeaves(root, res);          
        // all right nodes
        addRightBoundary(root->right, res);

        return res;
    }
};
