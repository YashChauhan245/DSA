https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == nullptr) {
                s += "#,";
            } else {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // remove the last comma --1,2,3,--->1,2,3

        if (!s.empty()) s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        // stringstream helps us extract values one at a time
        stringstream ss(data);//converting your string into a stream (like input
        string str;//store each extracted value
        getline(ss, str, ','); //Read from stream ss until you hit , and store it in str
        

        //this is only for 1st value of string ...other in loop
        TreeNode* root = new TreeNode(stoi(str));//string to int
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};
