//https://leetcode.com/problems/spiral-matrix/submissions/1674058831/\

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int rs=matrix.size();
        int cs=matrix[0].size();
        int count=0;
        int startingrow=0;
        int startingcol=0;
        int endingrow=rs-1;
        int endingcol=cs-1;
        int totalele=rs*cs;
        while(count<totalele){
            for(int i=startingcol;i<=endingcol && count<totalele;i++){
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            for(int i=startingrow;i<=endingrow && count<totalele;i++){
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            for(int i=endingcol;i>=startingcol && count<totalele;i--){
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            for(int i=endingrow;i>=startingrow && count<totalele;i--){
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;

        }
        return ans;
        
    }
};
