https://www.geeksforgeeks.org/problems/burning-tree/1

APPROACH-1)USING 3 PASS
class Solution {
  public:
    unordered_map<Node*, Node*> parent;

    // Step 1: Build parent map using DFS
    void addParent(Node* root) {
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

    // Step 2: DFS to find the node with the target value
    Node* findTarget(Node* root, int target) {
        if (root == NULL) return NULL;
        if (root->data == target) return root;
    
        Node* left = findTarget(root->left, target);
        if (left != NULL) return left;
    
        Node* right = findTarget(root->right, target);
        if (right != NULL) return right;
    
        return NULL;
    }   
    // Step 3: BFS to simulate the burning process
    int burnTree(Node* target) {
            queue<Node*> que;
            unordered_set<Node*> visited;
    
            que.push(target);
            visited.insert(target);
    
            int time = 0;
    
            while (!que.empty()) {
                int n = que.size();
                bool anySpread = false;
    
                while (n--) {
                    Node* curr = que.front(); 
                    que.pop();
    
                    if (curr->left && !visited.count(curr->left)) {
                        que.push(curr->left);
                        visited.insert(curr->left);
                        anySpread = true;
                    }
    
                    if (curr->right && !visited.count(curr->right)) {
                        que.push(curr->right);
                        visited.insert(curr->right);
                        anySpread = true;
                    }
    
                    if (parent.count(curr) && !visited.count(parent[curr])) {
                        que.push(parent[curr]);
                        visited.insert(parent[curr]);
                        anySpread = true;
                    }
                }
    
                if (anySpread) time++;
            }
    
            return time;
        }

    // Main function
    int minTime(Node* root, int target) {
        addParent(root);
        Node* targetNode = findTarget(root, target);
        return burnTree(targetNode);
    }
};




OPTIMISED-->USING 2 PASS

class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    Node* targetNode = NULL;

    // Step 1: Build parent map and find target node simultaneously
    void addParent(Node* root, int target) {
        if (!root) return;

        if (root->data == target) {
            targetNode = root;
        }

        if (root->left) {
            parent[root->left] = root;
            addParent(root->left, target);
        }

        if (root->right) {
            parent[root->right] = root;
            addParent(root->right, target);
        }
    }

    // Step 2: BFS to simulate the burning process
    int burnTree(Node* target) {
        queue<Node*> que;
        unordered_set<Node*> visited;

        que.push(target);
        visited.insert(target);

        int time = 0;

        while (!que.empty()) {
            int n = que.size();
            bool anySpread = false;

            while (n--) {
                Node* curr = que.front(); 
                que.pop();

                if (curr->left && !visited.count(curr->left)) {
                    que.push(curr->left);
                    visited.insert(curr->left);
                    anySpread = true;
                }

                if (curr->right && !visited.count(curr->right)) {
                    que.push(curr->right);
                    visited.insert(curr->right);
                    anySpread = true;
                }

                if (parent.count(curr) && !visited.count(parent[curr])) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]);
                    anySpread = true;
                }
            }

            if (anySpread) time++;
        }

        return time;
    }

    // Main function
    int minTime(Node* root, int target) {
        addParent(root, target);
        return burnTree(targetNode);
    }
};

