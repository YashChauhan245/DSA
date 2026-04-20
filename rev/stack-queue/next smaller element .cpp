https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        stack<int> st ;
        vector<int>ans(n,-1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) { //ans store 
                ans[i] = st.top();
            }
            st.push(arr[i]);//push new element in stack 
        }
    return ans;
        
    }
};
