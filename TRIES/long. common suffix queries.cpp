https://leetcode.com/problems/longest-common-suffix-queries/description/



class Solution {

public:

    struct trieNode {
        int idx;
        trieNode* child[26];

        ~trieNode() {
            for (int i = 0; i < 26; i++) {
                delete child[i];
            }
        }
    };

    trieNode* getNode(int i) {
        trieNode* tmp = new trieNode();
        tmp->idx = i;
        for (int i = 0; i < 26; i++) {
            tmp->child[i] = NULL;
        }
        return tmp;
    }

    void insertTrie(trieNode* root, int i, vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.size();

        for (int j = n - 1; j >= 0; j--) {
            int ch_idx = word[j] - 'a';

            if (root->child[ch_idx] == NULL) {
                root->child[ch_idx] = getNode(i);
            }

            root = root->child[ch_idx];

            if (wordsContainer[root->idx].size() > n) {
                root->idx = i;
            }
        }
    }

    int search(trieNode* root, string& word) {
        int res_idx = root->idx;
        int n = word.size();

        for (int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';
            root = root->child[ch_idx];
            if (root == NULL) return res_idx;
            res_idx = root->idx;
        }
        return res_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> ans(n);
        trieNode* root = getNode(0);

        for (int i = 0; i < m; i++) {
            int idx = root->idx;
            if (wordsContainer[idx].size() > wordsContainer[i].size()) {
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = search(root, wordsQuery[i]);
        }

        delete root; // destructor cleans everything
        return ans;
    }
};
