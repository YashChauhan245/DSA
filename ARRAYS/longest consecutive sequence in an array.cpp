//https://leetcode.com/problems/longest-consecutive-sequence/submissions/1673837765/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }
    for (auto it : st) {    //iterating  set and checking is x-1 is present
        if (st.find(it - 1) == st.end()) { //if not present  i.e its the starting pt.
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {  //now checking for x+1 ...(1,2,3...)
                x = x + 1;      //updating, so that loop runs till the last longest
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

                
    }
};
