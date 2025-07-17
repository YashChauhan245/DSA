https://leetcode.com/problems/largest-rectangle-in-histogram/description/

BRUTE->TOW PASS SOLN

class Solution {
public:
    vector<int>findnse(vector<int>&heights){
        stack<int>st;
        vector<int> nse(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpse(vector<int>&heights){
        stack<int>st;
        vector<int>pse(heights.size());
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;

        vector<int>pse=findpse(heights);
        vector<int>nse=findnse(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
        
    }
};


APPROACH-2)1 PASS SOLN

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0, n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int bar = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                area = max(area, heights[bar] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int bar = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = n;
            area = max(area, heights[bar] * (nse - pse - 1));
        }

        return area;
    }
};

