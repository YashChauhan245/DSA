https://leetcode.com/problems/decode-ways/description/


//recursion 

// class Solution {
// public:
//     int solver(string &s,int i){
//         if(i>=s.size()){
//             return 1;
//         }

//         if(s[i] == '0'){
//             return 0;
//         }

//         int takeone=solver(s,i+1);
//         int taketwo=0;
//         if(i + 1 < s.size()){ //EDGE CASE 
//             int num = (s[i]-'0')*10 + (s[i+1]-'0'); //type conversion
//             if(num >= 10 && num <= 26){
//                 taketwo = solver(s, i + 2);
//             }
//         }
//         return takeone+taketwo;
//     }
//     int numDecodings(string s) {
//         return solver(s,0);
//     }
// };



//top down 

// class Solution {
// public:
//     int solver(string &s,int i,vector<int>&dp){

//         if(i>=s.size()){
//             return 1;
//         }

//         if(s[i] == '0'){
//             return 0;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int takeone=solver(s,i+1,dp);
//         int taketwo=0;
//         if(i + 1 < s.size()){ 
//             int num = (s[i]-'0')*10 + (s[i+1]-'0'); 
//             if(num >= 10 && num <= 26){
//                 taketwo = solver(s, i + 2,dp);
//             }
//         }
//         dp[i]=takeone+taketwo;
//         return dp[i];
//     }
//     int numDecodings(string s) {
//         int n=s.size();
//         vector<int>dp(n+1,-1);
//         return solver(s,0,dp);
//     }
// };



//bottom up 

class Solution {
public:
    int solver(string &s,int i){
        int n=s.size();
        vector<int>dp(n+1,0);
        
        dp[n] = 1;   // base case

        for(int i=n-1;i>=0;i--){
//As dp is already assigned with 0 but If you remove it, this line will execute and the  algorithm will treat '0' as a valid single digit, which is incorrect.

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            int takeone=dp[i+1];
            int taketwo=0;
            if(i + 1 < n){ 
                int num = (s[i]-'0')*10 + (s[i+1]-'0'); 
                if(num >= 10 && num <= 26){
                    taketwo =dp[i+2];
                }
            }
            dp[i]=takeone+taketwo;
        }
        return dp[0];
    }

    int numDecodings(string s) {
        int n=s.size();
        return solver(s,0);
    }
};
