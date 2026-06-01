https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-06-01


// RECURSION 

// class Solution {
// public:
//     //12 possible first rows
//     string states[12] = {
//         "RYG", "RGY", "RYR", "RGR",
//         "YRG", "YGR", "YGY", "YRY",
//         "GRY", "GYR", "GRG", "GYG"
//     };
//     const int MOD = 1e9 + 7;

//     int solver(int n, int prev) {
//         if (n == 0) {
//             return 1;
//         }

//         string last = states[prev];
//         long long result = 0;

//         //choose pattern for ith row while checking prev pattern
//         for (int curr = 0; curr < 12; curr++) {
//             if (curr == prev)
//                 continue;
            
//             string currpattern = states[curr];
//             bool conflict = false;

//             //now curr row pattern is not same as prev so we can start filling column
//             //but check prev coln also
//             for (int col = 0; col < 3; col++) {
//                 if (currpattern[col] == last[col]) {
//                     conflict = true;
//                     break;
//                 }
//             }

//             //column filled
//             if (!conflict) {
//                 result = (result + solver(n - 1, curr)) % MOD;
//             }
//         }
//         return result;
//     }

//     int numOfWays(int n) {
//         long long result = 0;
//         for (int i = 0; i < 12; i++) {
//             //1st row pattern selected
//             result = (result + solver(n - 1, i)) % MOD;
//         }
//         return result;
//     }
// };




//top down 
class Solution {
public:
    //12 possible first rows
    string states[12] = {
        "RYG", "RGY", "RYR", "RGR",
        "YRG", "YGR", "YGY", "YRY",
        "GRY", "GYR", "GRG", "GYG"
    };

    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solver(int n, int prev) {
        if (n == 0) {
            return 1;
        }

        if (dp[n][prev] != -1) {
            return dp[n][prev];
        }

        string last = states[prev];
        long long result = 0;

        //choose pattern for ith row while checking prev pattern
        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev)
                continue;

            string currpattern = states[curr];
            bool conflict = false;

            //now curr row pattern is not same as prev so we can start filling column
            //but check prev coln also
            for (int col = 0; col < 3; col++) {
                if (currpattern[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }

            //column filled
            if (!conflict) {
                result = (result + solver(n - 1, curr)) % MOD;
            }
        }

        return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        dp.resize(n, vector<int>(12, -1));

        long long result = 0;

        for (int i = 0; i < 12; i++) {
            //1st row pattern selected
            result = (result + solver(n - 1, i)) % MOD;
        }

        return result;
    }
};
