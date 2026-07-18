https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/description/


class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans;
        for(char c: s){
            if(c==y){
                ans+=c;
            }
        }
        for( char c : s){
            if(c!=x && c!=y){
                ans+=c;
            }
        }
        for(char c: s){
            if(c==x){
                ans+=c;
            }
        }
        return ans;
    }
};
