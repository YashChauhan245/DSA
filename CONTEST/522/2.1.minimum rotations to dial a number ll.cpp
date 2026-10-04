https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/description/



class Solution {
public:
    int cost(int a,int b){
        int diff=abs(a-b);
        return min(diff,10-diff);
    }
    
    int minRotations(int n, string s) {
        int base=cost(0,s[0]-'0');
        for(int i=1;i<n;i++){
            base+=cost(s[i-1]-'0',s[i]-'0');
        }
        int ans=base;
        for(int k=0;k<n;k++){
            int candidate=base;
            if(k==0){
                candidate-=cost(0,s[0]-'0');
                candidate+=cost(0,s[n-1]-'0');
            }
            else{
                candidate-=cost(s[k-1]-'0',s[k]-'0');
                candidate+=cost(s[k-1]-'0',s[n-1]-'0');
            }
            ans=min(ans,candidate);
        }
        return ans;
    }
};
