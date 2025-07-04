class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int freqtable[26]={0};
            for(int j=i;j<s.size();j++){
                freqtable[s[j]-'a']++;
                int maxy=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freqtable[k]>0){
                        maxy=max(maxy,freqtable[k]);
                        mini=min(mini,freqtable[k]);
                    }
                }
                ans+=(maxy-mini);
            }
        }
        return ans;     
    }
};
