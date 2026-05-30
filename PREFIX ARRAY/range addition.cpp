https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0370.Range%20Addition/README_EN.md

class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& updates) {

        vector<int> ans(n, 0);

        // Difference array
        vector<int> psum(n + 1, 0);

        // For each update [l, r, val]:
        // start adding val at l
        // stop adding val after r
        for (int i = 0; i < updates.size(); i++) {
          //[updates[i][0]] & [updates[i][1+1]] me store kro [updates[i][2]] acc to sign
            psum[updates[i][0]] += updates[i][2];    
            psum[updates[i][1] + 1] -= updates[i][2];
        }

        // Prefix sum converts difference array
        // into the final modified array
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += psum[i];
            ans[i] = sum;
        }

        return ans;
    }
};
