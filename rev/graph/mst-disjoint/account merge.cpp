https://leetcode.com/problems/accounts-merge/description/

class Solution {
public:
    vector<int> parent, rank;

    // Find with path compression
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    // Union by rank (YOUR version)
    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } 
            else if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } 
            else {
                parent[root_j] = root_i;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        //Step 1: Initialize DSU
        parent.resize(n);
        rank.resize(n, 0);
        //independent nodes-->self parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        //Step 2: Map email -> account index
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (emailToAccount.find(mail) == emailToAccount.end()) {
                    // first time → store mapping
                    emailToAccount[mail] = i; //mail,number
                } else {
                    // same email → union accounts
                    Union(i, emailToAccount[mail]);
                }
            }
        }

        //Step 3: Group emails by parent account
        vector<vector<string>> mergedMail(n);

        for (auto &it : emailToAccount) {
            string mail = it.first;
            int accIndex = it.second;
            int parentNode = find(accIndex);
            mergedMail[parentNode].push_back(mail);
        }

        // Step 4:final answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // name

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
