https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/description/


//build maximal square dp 
//bin search the ans k--> if find non overlappong k*k squares -->if yes -->expand it else->try smaller
//find all possible k*k squares 

class Solution {
public:

    bool build(int k,vector<vector<int>>&dp,int m,int n){
        int minRow=INT_MAX,maxRow=INT_MIN;
        int minCol=INT_MAX , maxCol=INT_MIN;

        int count=0;
        for(int i=k-1;i<m;i++){
            for(int j=k-1;j<n;j++){
                if(dp[i][j]>=k){
                    int topRow=i-k+1;
                    int topCol=j-k+1;

                    minRow=min(minRow,topRow);
                    maxRow=max(maxRow,topRow);
                    minCol=min(minCol,topCol);
                    maxCol=max(maxCol,topCol);
                    count++;

                    if(count>=2 && (maxRow-minRow>=k || maxCol-minCol>=k)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    int maxArea(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    if(i==0||j==0){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=1+min({
                            dp[i-1][j],dp[i][j-1],dp[i-1][j-1]
                        });
                    }
                }
            }
        }

        int l=1;
        int h=min(m,n);
        int ans=0;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(build(mid,dp,m,n)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans*ans;
    }
};
