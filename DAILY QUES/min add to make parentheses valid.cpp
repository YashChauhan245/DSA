https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2026-10-06


class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for(char c : s) {
            if(c == '(') {
                balance++;
            }
            else {
                if(balance > 0) {
                    balance--;
                }
                else {
                    ans++;       
                }
            }
        }

        return ans + balance; 
    }
};
