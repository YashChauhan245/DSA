https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


class Solution {
public:
    unordered_map<int, int> mp; // stores value -> index in inorder

    // Recursive function to build tree
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        
        if (is > ie || ps > pe) return NULL;

        // Last element of postorder is always the ROOT
        int rootVal = postorder[pe];

        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder
        int inRoot = mp[rootVal];

        // Number of elements in left subtree
        int leftSize = inRoot - is;

        // Build LEFT subtree
        // inorder  → is → inRoot-1
        // postorder → ps → ps + leftSize - 1
        root->left = build(inorder, is, inRoot - 1,postorder, ps, ps + leftSize - 1);

        // Build RIGHT subtree
        // inorder  → inRoot+1 → ie
        // postorder → ps + leftSize → pe - 1
        root->right = build(inorder, inRoot + 1, ie,postorder, ps + leftSize, pe - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};
