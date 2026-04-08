https://leetcode.com/problems/word-ladder-ii/description/

//brute-->tle 
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if(st.find(endWord) == st.end()) return ans;

        queue<vector<string>> q;
        q.push({beginWord});

        bool found = false;

        while(!q.empty() && !found) {

            int size = q.size();
            unordered_set<string> usedInLevel; 

            for(int i = 0; i < size; i++) {
                vector<string> path = q.front();
                q.pop();
                string word = path.back(); // last word in path

                // if reached endWord
                if(word == endWord) {
                    ans.push_back(path);
                    found = true;
                }

                // try all transformations
                for(int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;
                        if(st.find(word) != st.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(word);
                            q.push(newPath);
                            usedInLevel.insert(word);
                        }
                    }

                    word[j] = original; // restore
                }
            }

            // remove words used in this level
            for(auto &w : usedInLevel) {
                st.erase(w);
            }
        }

        return ans;
    }
};


//optimal -->no need 

/* Phase 1 (BFS)
Explore level by level
Build parent map
Stop when endWord found

Phase 2 (DFS)
Start from endWord
Go backwards using parent map
Build all paths */


class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> res;

    void dfs(string word, string beginWord, vector<string>& path) {
        path.push_back(word);

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for (auto &p : parent[word]) {
                dfs(p, beginWord, path);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string temp = word;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[j] = ch;

                        if (st.count(temp)) {
                            parent[temp].push_back(word);

                            if (temp == endWord) {
                                found = true;
                            }

                            if (!visitedThisLevel.count(temp)) {
                                visitedThisLevel.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }

            // remove words after level
            for (auto &w : visitedThisLevel) {
                st.erase(w);
            }
        }

        if (!found) return {};

        vector<string> path;
        dfs(endWord, beginWord, path);

        return res;
    }
};

