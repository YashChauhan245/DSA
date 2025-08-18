https://leetcode.com/problems/climbing-stairs/

//recursive //tc->0(2n)

// class Solution {
// public:
//     int solver(int n){
//         if(n==0){
//             return 1;
//         }
//         if(n<0){
//             return 0;
//         }
//         int onestep=solver(n-1);
//         int twostep=solver(n-2);
//         return onestep+twostep;
//     }
//     int climbStairs(int n) {
//         int ans=solver(n);
//         return ans;
//     }
// };



//top-down-->0(n)
// class Solution {
// public:
//     int solver(int n,vector<int>&dp){
//         if(n==0){
//             return 1;
//         }
//         if(n<=){
//             return 0;
//         }
//         //step-3-->base case me agar ans present hai to just store it
//         if (dp[n]!=-1){
//             return dp[n];
//         }
//         //step 2-->store recursive ans
//         int onestep=solver(n-1,dp);
//         int twostep=solver(n-2,dp);
//         dp[n]=onestep+twostep;
//         return dp[n];
//     }
//     int climbStairs(int n) {
//         //step 1 -->create dp array 
//         vector<int>dp(n+1,-1);
//         return solver(n,dp);
//     }
// };


//bottom up->tc=0(n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         //create dp array 
//         vector<int> dp(n+1,-1);
//         //analyse base case
//         dp[0]=1;
//         dp[1]=1;this base case can be applied in both top down and recursive approach 
//         bcz if we start loop from 1 then i-2 is out of bound
//         //loop reverse as initially we are using n=3->n=0
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };



//space optimised -->s.c->0(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        // if(n<0){
        //     return 0;
        // }
        int prev=1;//for n=0
        int curr=1;//for n=1
        for(int i=2;i<=n;i++){
            int ans=prev+curr;
            prev=curr;
            curr=ans;
        }
    return curr;
    }
};
