https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int r=0;
        int l=0;
        int n=s.length();
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r++]=s[i++];
            }
            //** is loop se exit kra..i.e-->s[i]==' ';**
            // reverse [l and r]
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            //i iterate kra rhega jb ye sb ho jayega
            i++;
        }
        // trim-->extra spaces and words
        s=s.substr(0,r-1);
        // if (r > 0) s.resize(r - 1);  // remove trailing space
        // else s.resize(0);
        return s;
    }
};
