https://www.youtube.com/watch?v=4wsuveVWTrE

//recursion 
// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     int solve(int day, int delay, int forget) {
//         if (day == 1) return 1;  // first person
//         if (day <= 0) return 0;
//         long long result = 0;

//         //total person in that particular day
//         people who can share today are those who learned it in [day - forget + 1, day - delay]
//         for (int prev = day - forget + 1; prev <= day - delay; prev++) {
//             if (prev > 0) {
//                 result = (result + solve(prev, delay, forget)) % MOD;
//             }
//         }
//         return (int)result;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         long long total = 0;
//         // sum people who haven't forgotten by day n
//         for (int day = n - forget + 1; day <= n; day++) {
//             if (day > 0) {
//                 total = (total + solve(day, delay, forget)) % MOD;
//             }
//         }
//         return (int)total;
//     }
// };




//top down

// class Solution {
// public:
//     int MOD = 1e9 + 7;

//     int solve(int day, int delay, int forget, vector<int>& dp) {
//         if (day == 1) return 1;      // first person
//         if (day <= 0) return 0;
//         if (dp[day] != -1) return dp[day]; // use memo
//         long long result = 0;

//         for (int prev = day - forget + 1; prev <= day - delay; prev++) {
//             if (prev > 0) {
//                 result = (result + solve(prev, delay, forget, dp)) % MOD;
//             }
//         }

//         return dp[day] = (int)result; // store result in dp
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         vector<int> dp(n + 1, -1); // local dp vector inside main function
//         long long total = 0;

//         // sum people who haven't forgotten by day n
//         for (int day = n - forget + 1; day <= n; day++) {
//             if (day > 0) {
//                 total = (total + solve(day, delay, forget, dp)) % MOD;
//             }
//         }

//         return (int)total;
//     }
// };


//bottom up

class Solution {
public:
    int MOD = 1e9 + 7;
    int solver(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0); // dp[i] = people who first learn on day i
        dp[1] = 1;

        long long sum_window = 0; // sum of people who can share on current day

        for (int day = 2; day <= n; day++) {
            // Add dp[day - delay] to the window if day - delay >= 1
            if (day - delay >= 1) sum_window = (sum_window + dp[day - delay]) % MOD;
            // Remove dp[day - forget] from the window if day - forget >= 1
            if (day - forget >= 1) sum_window = (sum_window - dp[day - forget] + MOD) % MOD;

            dp[day] = sum_window;
        }

        long long total = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) total = (total + dp[day]) % MOD;
        }
        return (int)total;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        return solver(n, delay, forget);
    }
};



