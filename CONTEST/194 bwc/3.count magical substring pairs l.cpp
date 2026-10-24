https://leetcode.com/problems/count-magical-substring-pairs-i/description/


class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        long long ans=0;
        for(int j=0;j<n-1;j++){
            int lc[27]={0};
            int rc[27]={0};

            bool seen[26]={false};
            int dist=0;

            for(int i=j;i>=0;i--){
                int index=s[i]-'a';

                if(!seen[index]){
                    seen[index]=true;
                    dist++;
                }
                lc[dist]++;
            }

            bool seenRight[26]={false};
            dist=0;
            for(int k=j+1;k<n;k++){
                int index=s[k]-'a';

                if(!seenRight[index]){
                    seenRight[index]=true;
                    dist++;
                }
                rc[dist]++;
            }

            for(int count =1;count<=26;count++){
                ans+=1LL*lc[count]*rc[count];
            }
        }
        return (int)ans;
    }
};
