https://leetcode.com/problems/set-matrix-zeroes/

//Brute-->O(n*m) + O(k * (n + m)) + O(n*m)===>O(nm(n+m))

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Mark rows and cols
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {                    
                    // mark row
                    for(int k = 0; k < m; k++) {
                        if(matrix[i][k] != 0)
                            matrix[i][k] = -1;
                    }
                    // mark col
                    for(int k = 0; k < n; k++) {
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                }
            }
        }
        // Step 2: Convert -1 to 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};



//Better->o(n*m) sc->0(m+n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Step 1: Mark rows & cols
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // Step 2: Set zeros with respect to array
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



// Optimal ->o(m*n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first column separately
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                firstColZero = true;
        }

        // Check first row separately
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) 
                firstRowZero = true;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowZero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }

        if(firstColZero) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
        
    }
};
