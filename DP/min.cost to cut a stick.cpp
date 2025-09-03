https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/



//recursive
// class Solution {
// public:
//     int solver(vector<int>&cuts,int l,int r){
//         if(r-l<2){
//             return 0; //bcz atleast we want{l,c1,r} for cut 
//         }
//         int result=INT_MAX;
//         for(int i=l+1;i<=r-1;i++){
//             int cost=(cuts[r]-cuts[l])+solver(cuts,l,i)+solver(cuts,i,r);
//             result= min(result,cost);
//         }
//         return result;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         sort(cuts.begin(),cuts.end());
//         int size=cuts.size();
//         cuts.insert(begin(cuts),0);//zero at the starting
//         cuts.push_back(n); //n at the last
//         return solver(cuts,0,cuts.size()-1);
//     }
// };


//top down 

// class Solution {
// public:
//     int solver(vector<int>& cuts, int l, int r, vector<vector<int>>& dp) {
//         if (r - l < 2) {
//             return 0; // no cut possible
//         }

//         if (dp[l][r] != -1) return dp[l][r];

//         int result = INT_MAX;
//         for (int i = l + 1; i <= r - 1; i++) {
//             int cost = (cuts[r] - cuts[l]) 
//                      + solver(cuts, l, i, dp) 
//                      + solver(cuts, i, r, dp);
//             result = min(result, cost);
//         }

//         return dp[l][r] = result;
//     }

//     int minCost(int n, vector<int>& cuts) {
//         sort(cuts.begin(), cuts.end());
//         cuts.insert(cuts.begin(), 0); // stick start
//         cuts.push_back(n);            // stick end

//         int m = cuts.size();
//         vector<vector<int>> dp(m+1, vector<int>(m+1, -1));

//         return solver(cuts, 0, m - 1, dp);
//     }
// };



//bottom up

class Solution {
public:
    int solver(vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // fill from rightmost l to left
        for (int l = m - 2; l >= 0; l--) {
            for (int r = l + 2; r < m; r++) {  // interval must be valid
                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; i++) {  // forward loop
                    int cost = (cuts[r] - cuts[l]) + dp[l][i] + dp[i][r];
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }

        return dp[0][m - 1];
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);         
        return solver(cuts);
    }
};
