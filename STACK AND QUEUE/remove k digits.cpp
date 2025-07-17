https://leetcode.com/problems/remove-k-digits/description/


APPROACH-1)USING STACK VECTOR AND THEN VECTOR INTO STACK 
// KINDA COMPLEX 
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>result;
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if stack is like [1,2,3,6,8] && k=3 
        while(!st.empty()&& k>0){
            st.pop();
            k--;
        }
        // pushing into vector
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        // converting vector into string ..as output is in string 
        string finalResult(result.begin() + i, result.end());

        return finalResult.empty() ? "0" : finalResult;
    }
};



APPROACH-2)USING VECTOR AS STACK AND THEN CONVERT INTO STRING (USES LESS MEMORY)

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> result;

        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        // If there are still digits to remove
        while (k-- > 0 && !result.empty()) {
            result.pop_back();
        }

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        // Convert vector<char> to string
        string finalResult(result.begin() + i, result.end());

        return finalResult.empty() ? "0" : finalResult;
    }
};
