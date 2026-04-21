https://leetcode.com/problems/sum-of-subarray-minimums/description/+


typedef unsigned long long ll;
class Solution {
public:
    
    vector<int> getPSE(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) 
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }

    vector<int> getNSE(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) 
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> PSE = getPSE(arr, n); //Next smaller to left
        vector<int> NSE = getNSE(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - PSE[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSE[i] - i; //distance to nearest smaller to right from i
            
            ll total_subarray_from_i_element = d1*d2;
            ll sum_of_all_subarray= arr[i] * (total_subarray_from_i_element);
            
            sum  = (sum + sum_of_all_subarray)%M;
        }
        
        return sum;
        
    }
};
