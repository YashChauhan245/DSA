https://leetcode.com/problems/sum-of-subarray-minimums/description/

APPROACH-1)BRUTE BUT TLE 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        int minval=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            minval=arr[i];
            for(int j=i;j<arr.size();j++){
                minval=min(minval,arr[j]);
                sum=(sum+minval)%mod;
            }
        }
        return sum;
        
    }
};

APPROACH-2)STACK...

class Solution {
public:
    vector<int>getnsl(vector<int>& arr,int n){
        vector<int>result(n);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                result[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    result[i]=-1;
                }
                else{
                    result[i]=st.top();
                }
            }
            st.push(i);
        }
        return result;
    }

    vector<int>getnsr(vector<int>& arr,int n){ 
        vector<int>result(n);
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                result[i]=arr.size();
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    result[i]=arr.size();
                }
                else{
                    result[i]=st.top();
                }
            }
            st.push(i);
        }
        return result;  
    }
   
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=getnsl(arr,n);
        vector<int>nsr=getnsr(arr,n);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long ls=i-nsl[i];
            long long rs=nsr[i]-i;
            long long totalways=ls*rs;
            long long sumintotalways=arr[i]*totalways;
            sum=(sum+sumintotalways)%mod;
        }
        return sum; 
    }
};

