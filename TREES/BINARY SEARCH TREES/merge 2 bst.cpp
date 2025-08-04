https://leetcode.com/problems/binary-search-tree-iterator/description/

BRUTE->TC 0(1) AND SC O(N)

class BSTIterator {
public:
    vector<int> inorder;
    int index = 0;

    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < inorder.size();
    }
};



OPTIMISED ->USING STACK
T.C->O(1)
S.C->O(H)

class BSTIterator {
public:
    stack<TreeNode*>st;
    // pushing only left child and root
    void insertintostack(TreeNode*root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        insertintostack(root);
    }
    
    int next() {
        TreeNode*node= st.top();
        st.pop();
        // if right child present ...store all right child 
        if(node->right){
            insertintostack(node->right);
        }
        return node->val;
        
    }
    
    bool hasNext() {
        if(!st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

