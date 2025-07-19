https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int i=0;
        int j=0;
        int sum=0;
        int maxsum=INT_MIN;
        while(j<arr.size()){
          // calculation
            sum=sum+arr[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
              // ans store
                maxsum=max(maxsum,sum);
              //slide the window
                sum=sum-arr[i];
                i++;
                j++;
            }
            
        }
        return maxsum;
        
    }
};
