class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long int res=0;
        int sign=1;
        int n=s.size();
        // whitrspace 
        while(i<n && s[i]==' '){
            i++;
        }
        // sign
        if(i<n &&s[i]=='+'|| s[i]=='-'){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        // convert str into int
        while(i<n && isdigit(s[i])){
            res=res*10+(s[i]-'0');
            if(sign*res>=INT_MAX){
                return INT_MAX;
            }
            if(sign*res<=INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        // adding sign in final ans
        return (int)(sign*res);

        
    }
};
