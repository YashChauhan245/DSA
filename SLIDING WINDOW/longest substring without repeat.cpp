https://leetcode.com/problems/longest-substring-without-repeating-characters/

BRTUE:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            int hash[256]={0};
            for(int j=i;j<s.size();j++){
                if(hash[s[j]]==1){
                    break;
                }
                hash[s[j]]=1;
                int length=j-i+1;
                maxlen=max(maxlen,length);

            }
        }
        return maxlen;
        
    }
};




APPROACH-2)OPTIMAL

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int leng=0;
        int maxlen=0;
        int n=s.size();
        int hash[256];
        for (int i = 0; i < 256; ++i) {
            hash[i] = -1;
        }
        while(r<n){
            // if r is in the map
            if(hash[s[r]]!=-1){
                // r is in the same string 
                if(hash[s[r]]>=l){
                    // l->update
                    l=hash[s[r]]+1;
                }
            }
            leng=r-l+1;
            maxlen=max(maxlen,leng);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};
