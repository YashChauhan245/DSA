https://leetcode.com/problems/can-convert-string-in-k-moves/description/


/*
s[0] = 'a'
t[0] = 'b'
int shift = (t[i] - s[i] + 26) % 26;
shift = (1 + 26) % 26= 27 % 26 = 1
int move = shift + 26 * used[shift];
shift = 1
used[1] = 0
move = 1 + 26 * 0 = 1
*/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()){
            return false;
        }

        vector<int> used(26, 0);

        for (int i = 0; i < s.size(); i++) {
            int shift = (t[i] - s[i] + 26) % 26;
            if (shift == 0)
                continue;
            int move = shift + 26 * used[shift];
            if (move > k)
                return false;

            used[shift]++;
        }
        return true;
    }
};
