https://leetcode.com/problems/valid-parenthesis-string/description/

APPROACH-1)USING STACK 
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack, starStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            }
            else if (s[i] == '*') {
                starStack.push(i);
            }
            else { // s[i] == ')'
                if (!openStack.empty()) {
                    openStack.pop(); // match with '('
                }
                else if (!starStack.empty()) {
                    starStack.pop(); // treat '*' as '('
                }
                else {
                    return false; // no matching '(' or '*'
                }
            }
        }

        // Now match any remaining '(' with '*' acting as ')'
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() < starStack.top()) {
                openStack.pop();
                starStack.pop();
             }
            else {
                // '*' is before '(', invalid--->(**( IE NO CLOSING
                return false;
            }
        }

        return openStack.empty();
    }
};




APPROACH-2)USING GREEDY

class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        //Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
             //JAISE HI LESS THAN 0 AAYE RETURN FALSE; 
            if (open < 0) {
                return false;
            }
        }

        //Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            
            //JAISE HI LESS THAN 0 AAYE RETURN FALSE;
            if (close < 0) {
                return false;
            }
        }
        
        return true;
    }
};
