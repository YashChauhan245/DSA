https://leetcode.com/problems/remove-k-digits/description/



class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()){
            return "0";
        }

        stack<char> st;

        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        
        //store in ans
        vector<char> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        // remove leading zeros
        int i = 0;
        while(i < result.size() && result[i] == '0'){
            i++;
        }

        string finalResult(result.begin() + i, result.end());

        if(finalResult.empty()) return "0";//after rimming leading '0' nothing is left

        return finalResult;
    }
};
