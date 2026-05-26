https://leetcode.com/problems/jump-game-vii/?envType=daily-question&envId=2026-05-26

//TOP DOWN 
class Solution {
public:
    int n;

    bool solver(int i, string& s, int minJump, int maxJump, vector<int>& dp) {

        // reached last index
        if (i == n - 1)
            return true;

        // already calculated
        if (dp[i] != -1)
            return dp[i];

        // try all possible jumps
        for (int j = i + minJump; j <= min(n - 1, i + maxJump); j++) {

            // can jump only on '0'
            if (s[j] == '0') {

                // if reachable from here
                if (solver(j, s, minJump, maxJump, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {

        n = s.length();

        // dp[i] = can reach end from i or not
        vector<int> dp(n, -1);

        return solver(0, s, minJump, maxJump, dp);
    }
};


//BOTTOM UP
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        // dp[i] = can reach index i or not
        vector<int> dp(n, false);

        // starting position
        dp[0] = true;

        // fill dp from left to right
        for (int i = 0; i < n; i++) {

            // current index not reachable
            if (!dp[i])
                continue;

            // try jumps in reverse order
            for (int j = min(n - 1, i + maxJump);
                 j >= i + minJump;
                 j--) {

                // can jump only on '0'
                if (s[j] == '0') {
                    dp[j] = true;
                }
            }
        }

        return dp[n - 1];
    }
};

//SLIDING WINDOW + BOTTOM UP
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        // dp[i] = can reach index i or not
        vector<int> dp(n, false);

        dp[0] = true;

        int reachable = 0;

        // traverse from left to right
        for (int i = 1; i < n; i++) {

            // add new index entering window
            if (i - minJump >= 0)
                reachable += dp[i - minJump];

            // remove old index leaving window
            if (i - maxJump - 1 >= 0)
                reachable -= dp[i - maxJump - 1];

            // current position is reachable
            if (s[i] == '0' && reachable > 0)
                dp[i] = true;
        }

        return dp[n - 1];
    }
};
