https://leetcode.com/problems/longest-string-chain/description/

//recursive
// class Solution {
// public:
//     bool ispredecessor(const string& prev, const string& curr){
//         int n=prev.length();
//         int m=curr.length();
//         if(n>=m ||m-n!=1){
//             return false;
//         }
//         int a=0;int b=0;
//         while(a<n &&b<m){
//             if(prev[a]==curr[b]){
//                 a++;
//                 b++;
//             }
//             else{
//                 b++;
//             }
//         }
//         return a==n; //check if prev fully matched
//     }
//     int solver(vector<string>&words,int i,int prev){
//         if(i==words.size()){
//             return 0;
//         }
//         int take=0;
//         if(prev==-1 ||ispredecessor(words[prev],words[i])){
//             take=1+solver(words,i+1,i);
//         }
//         int skip=solver(words,i+1,prev);
//         return max(take,skip);
//     }
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(), [](const string& a, const string& b){return a.size() < b.size(); }); 

//         return solver(words,0,-1);
//     }
// };



//top down 
// class Solution {
// public:
//     bool ispredecessor(const string& prev, const string& curr) {
//         int n = prev.length();
//         int m = curr.length();
//         if (m - n != 1) return false;

//         int a = 0, b = 0;
//         while (a < n && b < m) {
//             if (prev[a] == curr[b]) {
//                 a++;
//                 b++;
//             } else {
//                 b++; // skip one character in curr
//             }
//         }
//         return a == n; // check if prev fully matched
//     }

//     int solver(vector<string>& words, int i, int prev, vector<vector<int>>& dp) {
//         if (i == words.size()) return 0;

//         if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

//         int take = 0;
//         if (prev == -1 || ispredecessor(words[prev], words[i])) {
//             take = 1 + solver(words, i + 1, i, dp);
//         }

//         int skip = solver(words, i + 1, prev, dp);

//         return dp[i][prev + 1] = max(take, skip);
//     }

//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(),
//              [](const string& a, const string& b) { return a.size() < b.size(); });

//         int n = words.size();
//         vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));

//         return solver(words, 0, -1, dp);
//     }
// };






//bottom up 

class Solution {
public:
    bool isPredecessor(const string& prev, const string& curr) {
        int n = prev.length(), m = curr.length();
        if (m - n != 1) return false;

        int a = 0, b = 0;
        while (a < n && b < m) {
            if (prev[a] == curr[b]) {
                a++; b++;
            } else {
                b++; // skip one char in curr
            }
        }
        return a == n;
    }

    int solver(vector<string>& words) {
        // sort inside solver
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) { return a.size() < b.size(); });

        int n = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // bottom-up reverse loop
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || isPredecessor(words[prev], words[i])) {
                    take = 1 + dp[i + 1][i + 1];
                }
                int skip = dp[i + 1][prev + 1];
                dp[i][prev + 1] = max(take, skip);
            }
        }

        return dp[0][0]; // (i=0, prev=-1 → shifted to 0)
    }

    int longestStrChain(vector<string>& words) {
        return solver(words);
    }
};
