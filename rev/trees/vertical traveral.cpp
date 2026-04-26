https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<x, map<y, multiset<node values>>>
        map<int, map<int, multiset<int>>> mp;
        // queue for BFS traversal: stores {node, {x, y}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // root at x=0, y=0

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int x = front.second.first;   // vertical level
            int y = front.second.second;  // depth level
            //storing in multiset
            mp[x][y].insert(node->val);
             // if left ..push in ques 
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            // if right.... push in queue
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Construct the result
        vector<vector<int>> result;
        // traversing map for vertical view
        for (auto& col : mp) {
            vector<int> temp;
           // col.second is multiset in map 
          // traverisng each col/vertical levle from top to bootm
            for (auto& row : col.second) {
                // position,start,end)
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }

            result.push_back(temp);
        }

        return result;
    }
};
