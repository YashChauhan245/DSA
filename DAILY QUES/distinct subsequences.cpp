http://leetcode.com/problems/distinct-subsequences/description/?envType=daily-question&envId=2026-09-06


//TOP DOWN 
class Solution {
public:

   int solver(string s, string t,int i,int j,vector<vector<int>>&dp){
        if (j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            //2 cases--->match it or explore further
            dp[i][j]= solver(s,t,i+1,j+1,dp) + solver(s,t,i+1,j,dp);
            return dp[i][j];
        }
        else{
            dp[i][j]= solver(s,t,i+1,j,dp);
            return dp[i][j];
        }
   }
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solver(s,t,0,0,dp);
    }
};



//SPACE OPTIMISED
class Solution {
public:
    typedef unsigned long long ull;
    
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<ull> curr(n+1, 0); //Replace dp[i] with curr
        vector<ull> prev(n+1, 0); //Replace dp[i-1] with prev
        
        prev[0] = curr[0] = 1;
        
        for(int i = 1; i<m+1; i++) {
            
            for(int j = 1; j<n+1; j++) {
                
                if(s[i-1] == t[j-1])
                    curr[j] = prev[j-1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[n];
    }
};
