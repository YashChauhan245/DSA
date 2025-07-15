https://leetcode.com/problems/next-greater-element-ii/description/

APPROACH-1)T.C->O(N2)
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  
        for (int i = 0; i < n; ++i) {
          // CIRCULAR LOOP 
            for (int j = i + 1; j <i+n; ++j) {
                int idx=j%n;
                if (nums[idx] > nums[i]) {
                    ans[i] = nums[idx];
                    break;
                }
            }
        }
        return ans;
    }
};


APPROACH-2) O(4n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; --i) {
            int curr = nums[i % n];
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }
            st.push(curr);
        }

        return ans;
    }
};

APPROACH-2) T.C->
