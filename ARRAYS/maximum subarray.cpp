https://leetcode.com/problems/maximum-subarray/description/


class Solution {
public:
    int maxSubArray(vector<int>& nums){

// // Brute force:TLE
//         int maxsum=INT_MIN;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 if(sum>maxsum){
//                     maxsum=max(sum,maxsum);
//                 }

//             }
//         }
//         return maxsum;


// OPTIMISED-->KADENE ALGO
        int sum=0;
        int maxy=INT_MIN;
        int n=nums.size();
        // int start = 0, s = 0, e = 0;     //if asked to print that particulr subaaray
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum>maxy){
                maxy=sum;
               //s = start;   // update subarray start
              // e = i;      // update subarray end

            }
            if(sum<0){
                sum=0;
               // start = i + 1;  //  new subarray start
            }
        }
        return maxy;

    }
};
