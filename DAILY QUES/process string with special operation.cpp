https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16


class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string res="";

        for(int i=0;i<n;i++){
            if(islower(s[i])){
                res+=s[i];
            }
            else if(s[i]=='*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }
            else if(s[i]=='#'){
                res+=res;
            }
            else if(s[i]=='%'){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};
