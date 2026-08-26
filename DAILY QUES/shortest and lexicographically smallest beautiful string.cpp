https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26



// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         string ans = "";
//         int bestLen = INT_MAX;

//         int n = s.size();

//         for (int i = 0; i < n; i++) {
//             int ones = 0;

//             for (int j = i; j < n; j++) {
//                 if (s[j] == '1')
//                     ones++;

//                 if (ones == k) {
//                     string cur = s.substr(i, j - i + 1);

//                     if (cur.length() < bestLen) {
//                         bestLen = cur.length();
//                         ans = cur;
//                     }
//                     else if (cur.length() == bestLen && cur < ans) {
//                         ans = cur;
//                     }

//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;

                left++;
            }
            if (ones == k) {
                while (left < right && s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                if (ans == "" ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {

                    ans = cur;
                }
            }
        }
        return ans;
    }
};
