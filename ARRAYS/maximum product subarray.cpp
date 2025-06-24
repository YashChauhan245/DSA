https://leetcode.com/problems/maximum-product-subarray/submissions/1675052257/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
    // Brute force-->TLE AND O(N2):

        // int maxprod=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int currprod=1;
        //     for(int j=i;j<nums.size();j++){
        //         currprod*=nums[j];
        //         maxprod=max(maxprod,currprod);
        //     }
        // }
        // return  maxprod;

//OPtimised-->Kadene algo
        int maxi=INT_MIN;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if (prod==0) prod=1;
        }

//backward pass --->for caases like [3,-1,4]
        prod = 1;//maxi still same jus prod=1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxi = max(maxi, prod);
            if (prod == 0) prod = 1;
        }
        return maxi;
    }
};
