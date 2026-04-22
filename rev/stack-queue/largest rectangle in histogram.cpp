https://leetcode.com/problems/largest-rectangle-in-histogram/description/


//APPROACH-1
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


//APPROACH-2
class Solution {
  public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st;
        int maxA = 0;  
        int n = histo.size();

        for (int i = 0; i <= n; i++) {
            
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; 
                st.pop(); 

                int width;
                if (st.empty()) {
                    width = i; // All bars before were higher
                } else {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                maxA = max(maxA, width * height);
            }
            // Push current index into stack
            st.push(i);
        }
        return maxA;
    }
};
