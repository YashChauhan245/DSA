https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        for(string str:strs) {
            int countOnes  = 0;
            int countZeros = 0;
            
            for(char ch:str) {
                if(ch == '1')
                    countOnes++;
                else
                    countZeros++;
            }
            
            for(int zero = m; zero >= countZeros; zero--) {
                for(int one = n; one >= countOnes; one--) {
                    t[zero][one] = max(t[zero][one], t[zero-countZeros][one-countOnes] + 1); //(exclude(previous value), include)
                }
            }
            
        }
        
        return t[m][n];
    }
};
