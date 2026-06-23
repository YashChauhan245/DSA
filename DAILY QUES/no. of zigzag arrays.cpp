https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-23

/*
OPTIMAL APPROACH

State Compression:
Instead of storing (prev2, prev1),
store:

dp[len][dir][value]

dir = 1 => last move was UP
dir = 0 => last move was DOWN

Observation:
To make an UP move ending at value j,
the previous value must be > j and the previous direction
must be DOWN.

To make a DOWN move ending at value j,
the previous value must be < j and the previous direction
must be UP.

The transitions require sums over ranges.

Use:
1. Prefix sums  -> O(1) range query
2. Difference array -> O(1) range update

This reduces the complexity from O(n * range²)
to O(n * range).
*/

constexpr auto Mod(const long long value) {
    constexpr auto mod = static_cast<int>(1e9) + 7;

    // keeps value inside [0, MOD)
    return static_cast<int>(((value % mod) + mod) % mod);
}

class Solution {
public:
    int zigZagArrays(const int n, const int l, const int r) {

        // dp[len][dir][value]
        auto dp = vector(n, vector(2, vector<long long>(r + 1)));

        /*
            Base Case

            len = 0 means arrays of length 2

            dir = 1 (UP)

            Example:
            l = 1, r = 3

            Valid UP pairs:
            (1,2)
            (1,3)
            (2,3)

            Store as prefix counts.
        */

        dp[0][1][l + 1] = 1;

        for (auto i = l + 2; i <= r; ++i) {
            dp[0][1][i] = 1 + dp[0][1][i - 1];
        }

        /*
            dir = 0 (DOWN)

            Valid DOWN pairs:
            (3,2)
            (3,1)
            (2,1)

            Store as suffix/prefix style counts.
        */

        dp[0][0][r - 1] = 1;

        for (auto i = r - 2; i >= l; --i) {
            dp[0][0][i] = 1 + dp[0][0][i + 1];
        }

        /*
            Build answers for larger lengths

            i = current DP layer
            (length = i + 2)
        */
        for (auto i = 1; i < n; ++i) {

            for (auto j = l; j <= r; ++j) {

                /*
                    Build UP states

                    Need:
                    previous direction = DOWN
                    previous value > j

                    Range query using prefix sums:
                    count(values > j)
                */
                dp[i][1][j] += dp[i - 1][0][l] - dp[i - 1][0][j];

                Mod(dp[i][1][j]);

                /*
                    Build DOWN states

                    Need:
                    previous direction = UP
                    previous value < current value

                    Use difference array trick
                    to update a whole range in O(1).
                */
                if (j < r) {

                    auto count =
                        Mod(dp[i - 1][1][r] - dp[i - 1][1][j]);

                    // range add starts
                    dp[i][0][l] += count;

                    // range add ends
                    dp[i][0][j + 1] -= count;
                }
            }

            /*
                Convert difference array
                back into actual values.

                Also rebuild prefix sums
                for the next DP layer.
            */
            for (auto j = l + 1; j <= r; ++j) {

                dp[i][0][j] += dp[i][0][j - 1];
                dp[i][1][j] += dp[i][1][j - 1];
            }
        }

        /*
            Final answer:

            DOWN states stored at index l
            UP states stored at index r
        */
        return Mod(dp[n - 1][0][l] + dp[n - 1][1][r]);
    }
};

/* BRUTE APPORACH :
Generate all arrays of length n
When an array is complete, call checkvalid()
If valid, increment count
Return count */

class Solution {
public:
    const int mod = 1e9 + 7;

    bool checkvalid(vector<int>& arr) {

        // No two adjacent elements are equal
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1])
                return false;
        }

        // No three consecutive elements are strictly
        // increasing or strictly decreasing
        for (int i = 2; i < arr.size(); i++) {
            if ((arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) ||
                (arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i])) {
                return false;
            }
        }

        return true;
    }

    void solver(int n, int l, int r, vector<int>& arr, long long & count) {

        if (arr.size() == n) {
            if (checkvalid(arr))
                count=(count+1)%mod;

            return;
        }
        
        //find all arrays
        for (int x = l; x <= r; x++) {
            arr.push_back(x);
            solver(n, l, r, arr, count);
            arr.pop_back();
        }
    }

    int zigZagArrays(int n, int l, int r) {

        long long  count = 0;
        vector<int> arr;

        solver(n, l, r, arr, count);

        return count;
    }
};


//TOP DOWN -->TLE
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int solver(int curr, int prev2, int prev1,int n,int l,int r,vector<vector<vector<int>>>& dp) {

        if (curr == n)
            return 1;

        if (dp[curr][prev2][prev1] != -1)
            return dp[curr][prev2][prev1];

        long long ans = 0;

        for (int next = l; next <= r; next++) {

            // adjacent elements cannot be equal
            if (next == prev1)
                continue;

            // no strictly increasing triple
            if (prev2 < prev1 && prev1 < next)
                continue;

            // no strictly decreasing triple
            if (prev2 > prev1 && prev1 > next)
                continue;

            ans += solver(curr + 1,prev1,next, n,l, r,dp);

            ans %= MOD;
        }

        return dp[curr][prev2][prev1] = (int)ans;
    }

    int zigZagArrays(int n, int l, int r) {

        if (n == 1)
            return r - l + 1;

        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(r + 1,vector<int>(r + 1, -1)));

        long long ans = 0;

        for (int first = l; first <= r; first++) {
            for (int second = l; second <= r; second++) {

                if (first == second)
                    continue;

                ans += solver(2,first,second,n,l,r,dp);

                ans %= MOD;
            }
        }

        return ans;
    }
};


/*
OPTIMAL APPROACH

State Compression:
Instead of storing (prev2, prev1),
store:

dp[len][dir][value]

dir = 1 => last move was UP
dir = 0 => last move was DOWN

Observation:
To make an UP move ending at value j,
the previous value must be > j and the previous direction
must be DOWN.

To make a DOWN move ending at value j,
the previous value must be < j and the previous direction
must be UP.

The transitions require sums over ranges.

Use:
1. Prefix sums  -> O(1) range query
2. Difference array -> O(1) range update

This reduces the complexity from O(n * range²)
to O(n * range).
*/

constexpr auto Mod(const long long value) {
    constexpr auto mod = static_cast<int>(1e9) + 7;

    // keeps value inside [0, MOD)
    return static_cast<int>(((value % mod) + mod) % mod);
}

class Solution {
public:
    int zigZagArrays(const int n, const int l, const int r) {

        // dp[len][dir][value]
        auto dp = vector(n, vector(2, vector<long long>(r + 1)));

        /*
            Base Case

            len = 0 means arrays of length 2

            dir = 1 (UP)

            Example:
            l = 1, r = 3

            Valid UP pairs:
            (1,2)
            (1,3)
            (2,3)

            Store as prefix counts.
        */

        dp[0][1][l + 1] = 1;

        for (auto i = l + 2; i <= r; ++i) {
            dp[0][1][i] = 1 + dp[0][1][i - 1];
        }

        /*
            dir = 0 (DOWN)

            Valid DOWN pairs:
            (3,2)
            (3,1)
            (2,1)

            Store as suffix/prefix style counts.
        */

        dp[0][0][r - 1] = 1;

        for (auto i = r - 2; i >= l; --i) {
            dp[0][0][i] = 1 + dp[0][0][i + 1];
        }

        /*
            Build answers for larger lengths

            i = current DP layer
            (length = i + 2)
        */
        for (auto i = 1; i < n; ++i) {

            for (auto j = l; j <= r; ++j) {

                /*
                    Build UP states

                    Need:
                    previous direction = DOWN
                    previous value > j

                    Range query using prefix sums:
                    count(values > j)
                */
                dp[i][1][j] += dp[i - 1][0][l] - dp[i - 1][0][j];

                Mod(dp[i][1][j]);

                /*
                    Build DOWN states

                    Need:
                    previous direction = UP
                    previous value < current value

                    Use difference array trick
                    to update a whole range in O(1).
                */
                if (j < r) {

                    auto count =
                        Mod(dp[i - 1][1][r] - dp[i - 1][1][j]);

                    // range add starts
                    dp[i][0][l] += count;

                    // range add ends
                    dp[i][0][j + 1] -= count;
                }
            }

            /*
                Convert difference array
                back into actual values.

                Also rebuild prefix sums
                for the next DP layer.
            */
            for (auto j = l + 1; j <= r; ++j) {

                dp[i][0][j] += dp[i][0][j - 1];
                dp[i][1][j] += dp[i][1][j - 1];
            }
        }

        /*
            Final answer:

            DOWN states stored at index l
            UP states stored at index r
        */
        return Mod(dp[n - 1][0][l] + dp[n - 1][1][r]);
    }
};


