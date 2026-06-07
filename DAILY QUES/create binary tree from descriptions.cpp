https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2026-06-07

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;//value<->treenode address mapping to store node created or not 
        unordered_set<int> childSet; //they can never be root of the tree

        for(vector<int>& vec : descriptions) { 
            int parent = vec[0]; //20
            int child  = vec[1]; //15
            int isLeft = vec[2]; //left child or right

            if(mp.find(parent) == mp.end()) {     //create parent node
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {     //create child node
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child); //store child
        }


        //Find the root 
        for(vector<int>& vec : descriptions) { 
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if parent not found in child set return it 
                return mp[parent];
            }
        }

        return NULL; 
    }
};
