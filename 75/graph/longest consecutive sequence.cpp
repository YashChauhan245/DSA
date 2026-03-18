https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int dfs(int node, unordered_set<int>& st) {
        if (st.find(node) == st.end()) return 0;

        st.erase(node); // mark visited

        int count = 1;
        //neighbours explore
        count += dfs(node - 1, st);   //explore left
        count += dfs(node + 1, st);  //explore right

        return count;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums) {
            if (st.find(num) != st.end()) {  //not visited 
                int size = dfs(num, st);     //dfs for that number and get size
                ans = max(ans, size);       //get ans 
            }
        }

        return ans;
    }
};
