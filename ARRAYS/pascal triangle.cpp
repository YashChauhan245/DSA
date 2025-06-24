https://leetcode.com/problems/pascals-triangle/submissions/1674651218/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
        for(int i=0;i<numRows;i++){
            result[i]=vector<int>(i+1,1);//i+1-->total element in that row, and initialize with 1
            for(int j=1;j<i;j++){//col=1-->col=i....eg i=0;
                result[i][j]=result[i-1][j]+result[i-1][j-1];
            }
        }
        return result;
    }
};
