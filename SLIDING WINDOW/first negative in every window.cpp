https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

BRUTE :TLE 
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int>ans;
        for(int i=0;i<=arr.size()-k;i++){
            bool found=false;
            for(int j=i;j<i+k;j++){
                if(arr[j]<0){
                    found=true;
                    ans.push_back(arr[j]);
                    break;
                }
            }
            if(found!=true){
                ans.push_back(0);
            }
        }
        return ans;
    }
};



OPTIMISED-USING SLIDING +DEQUE

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int i=0;
        int j=0;
        vector<int>ans;
        deque<int>dq;
        int n=arr.size();
        while(j<n){
            // calculation
            if(arr[j]<0){
                dq.push_back(arr[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                // store ans
                if(!dq.empty()){
                    ans.push_back(dq.front());
                }
                else{
                    ans.push_back(0);
                }
                // slide the window
                if(!dq.empty() && arr[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
                
            }
        }
        return ans;
        
    }
};
