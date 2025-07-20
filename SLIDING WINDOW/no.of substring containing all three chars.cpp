https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0; 
        unordered_map<char, int> mp {{'a', 0}, {'b', 0}, {'c', 0}};
        int i = 0, j = 0;

        while(j < n) {
            mp[s[j]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                result += (n - j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};
