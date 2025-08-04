https://www.geeksforgeeks.org/problems/largest-bst/1

class Solution {
  public:
    // Helper function
    int helper(Node* root, int &minVal, int &maxVal, int &maxSize) {
        // Base case: empty tree is a BST
        if (!root) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return 0;
        }

        int leftMin, leftMax, rightMin, rightMax;

        // Recursively get sizes of left and right subtrees
        int leftSize = helper(root->left, leftMin, leftMax, maxSize);
        int rightSize = helper(root->right, rightMin, rightMax, maxSize);

        // Check if the subtree rooted at current node is a BST
        if ((root->left == NULL || leftMax < root->data) &&
            (root->right == NULL || root->data < rightMin)) {

            // Update current subtree's min and max
            if (root->left != NULL) {
                minVal = leftMin;
            } else {
                minVal = root->data;
            }

            // Set maxVal
            if (root->right != NULL) {
                maxVal = rightMax;
            } else {
                maxVal = root->data;
            }

            // Update maxSize if needed
            int currSize = leftSize + rightSize + 1;
            maxSize = max(maxSize, currSize);

            return currSize;
        }

        // If not BST, return 0 and set invalid bounds
        minVal = INT_MIN;
        maxVal = INT_MAX;
        return 0;
    }

    // Main function to return size of largest BST
    int largestBst(Node *root) {
        int minVal, maxVal;
        int maxSize = 0;
        helper(root, minVal, maxVal, maxSize);
        return maxSize;
    }
};
