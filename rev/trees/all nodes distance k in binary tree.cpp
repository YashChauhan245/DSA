https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/


class Solution {
public:
    // Step 1: Create mapping of child -> parent
    unordered_map<TreeNode*, TreeNode*> parent;

    void addParent(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            addParent(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            addParent(root->right);
        }
    }

    // Step 2: BFS from target node to collect all nodes at distance k
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!que.empty()) {
            int size = que.size();
            if (k == 0) break;

            while (size--) {
                TreeNode* curr = que.front();
                que.pop();

                if (curr->left && !visited.count(curr->left)) {
                    que.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    que.push(curr->right);
                    visited.insert(curr->right);
                }
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;
        }

        // All nodes left in the queue are at distance k
        while (!que.empty()) {
            result.push_back(que.front()->val);
            que.pop();
        }
    }

    // Main function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        addParent(root);
        collectKDistanceNodes(target, k, result);
        return result;
    }
};
