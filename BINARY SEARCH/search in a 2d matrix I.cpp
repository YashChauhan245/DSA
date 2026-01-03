https://leetcode.com/problems/search-a-2d-matrix/description/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int s=0;
        int e=m*n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(matrix[mid/n][md%n]>target){
                e=mid-1;
            }
            else if(matrix[mid/n][mid%n]<target){
                s=mid+1;
            }
            else{
                return true;
            }
        }
        return false;   
    }
};
