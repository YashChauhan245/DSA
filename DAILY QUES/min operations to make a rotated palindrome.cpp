https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/description/



/* s=yb....a=24,b=1
int a = left - 'a';
int b = right - 'a';

(a - b + 26) % 26
= (24 - 1 + 26) % 26
= 23

(b - a + 26) % 26
= (1 - 24 + 26) % 26
= 3 
*/


class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for (int k = 0; k < n; k++) {
            int cost = k;  // k rotations

            for (int i = 0; i < n / 2; i++) {
                int j = n - 1 - i;

                int a = s[(i + k) % n] - 'a';
                int b = s[(j + k) % n] - 'a';

                int c1 = (a - b + 26) % 26;
                int c2 = (b - a + 26) % 26;

                cost += min(c1, c2);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};
