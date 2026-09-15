https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/?envType=daily-question&envId=2026-09-15



class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<pair<int, int>> palindromes;
        for (int center = 0; center < n; center++) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    palindromes.push_back({l, r});
                }
                l--;
                r++;
            }
            l = center;
            r = center + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    palindromes.push_back({l, r});
                }
                l--;
                r++;
            }
        }

    //COUNTER OVERLAPPING -->PREFER STRING THAT FINISH EARLY
        // Sort by ending position
        sort(palindromes.begin(), palindromes.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second < b.second;
             });

        int count = 0;
        int lastEnd = -1;

        // Select maximum number of non-overlapping palindromes
        for (auto p : palindromes) {
            int l = p.first;
            int r = p.second;
            if (l > lastEnd) {
                count++;
                lastEnd = r;
            }
        }
        return count;
    }
};
