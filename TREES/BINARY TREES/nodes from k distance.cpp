https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/1718473777/


APPROACH-1)just storing {int} data type in set;

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void addParent(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left){
            parent[root->left] = root;
            addParent(root->left);
        }
        
        if(root->right){
            parent[root->right] = root;
            addParent(root->right);
        }
    }
    
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0)
                break;
            
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParent(root);
        
        collectKDistanceNodes(target, k, result);
        return result;
    }
};


Approach-2)using {TREENODE*} IN SET

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
            int n = que.size();
            if (k == 0) break;

            while (n--) {
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
