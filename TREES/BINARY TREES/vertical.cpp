https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store: verLevel (x) -> level (y) -> set of node values
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;   //nodes,x,level
        q.push({root, {0, 0}});  // root is at x=0, y=0

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> p = q.front(); //auto p=q.front();
            q.pop();

            TreeNode* node = p.first;
            int verLevel = p.second.first;
            int level = p.second.second;
            // store this in ds
            nodes[verLevel][level].insert(node->val);
           // if left ..push in ques 
            if (node->left) {
                q.push({node->left, {verLevel - 1, level + 1}});
            }
          // if right push in queue
            if (node->right) {
                q.push({node->right, {verLevel + 1, level + 1}});
            }
        }
        vector<vector<int>> result;
      // traversing map for vertical view
        for (auto& col : nodes) {
            vector<int> temp;
          // col.second is multiset in map 
          // traverisng each col/vertical levle from top to bootm
            for (auto& row : col.second) {
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};
