https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=graph-theory



class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        queue<string> q;
        q.push(startGene);

        int mutations = 0;

        string chars = "ACGT";

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string current = q.front();
                q.pop();

                if (current == endGene) {
                    return mutations;
                }

                for (int i = 0; i < 8; i++) {
                    char original = current[i];

                    for (char c : chars) {
                        current[i] = c;

                        if (st.count(current)) {
                            q.push(current);
                            st.erase(current);
                        }
                    }

                    current[i] = original;
                }
            }

            mutations++;
        }

        return -1;
    }
};
