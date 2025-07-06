https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:

    int helper(const string &s,int i,long long result,int sign){
        // base condn
        if(i>=s.size() || !isdigit(s[i])){
            return result*sign;
        }
        // converting func
        result=result*10+(s[i]-'0');
        if(sign==1 && result>=INT_MAX){
            return INT_MAX;
        }
        if(sign==-1 && -result<=INT_MIN){
            return INT_MIN;
        }
        return helper(s,i+1,result,sign);

    }
    int myAtoi(string s){
        // whitespace ignore
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        // sign store
        int sign =1;
        if(i<s.size()&& (s[i]=='+' || s[i]=='-')){
            if (s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        return helper(s,i,0,sign);//0-->result
    }
};
