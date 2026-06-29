https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/


class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        //using arr[0]; -->base case
        int i;
        int power=INT_MIN;
        int nopower=arr[0];
        int res=arr[0];

        for(int i=1;i<n;i++){
            int v1=nopower+arr[i];  //merge in original arr
            int v2=arr[i];         //start now subarray
            int v3 = (power == INT_MIN) ? INT_MIN : power + arr[i];  
            //Merge with arr that already used power in the past
            int v4=nopower;       //skip current element as we used the power now

            //update power and no power states for further iteration
            nopower=max(v1,v2);
            power=max(v3,v4);
            
            res=max(res,max(power,nopower)); 

        }
        return res;
    }
};
