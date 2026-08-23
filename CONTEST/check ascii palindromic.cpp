https://leetcode.com/problems/check-ascii-palindromic/description/



class Solution {
public:
    bool isPalindromic(string s) {
        string bn="";
        for(char c:s){
            int x=(int)c;
            for(int i=7;i>=0;i--){  //convert to ascii
                bn+=((x>>i) & 1)+'0';    
            }
        }
        int l=0,r=bn.size()-1;
        while(l<r){
            if(bn[l]!=bn[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
