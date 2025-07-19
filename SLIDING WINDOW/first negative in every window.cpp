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

