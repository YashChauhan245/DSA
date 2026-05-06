https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/description/


//TLE 
class Solution {
public:
    long long minOperations(vector<int>& nums) {
       
        int n = nums.size();

        //convert into long long vector to avoid overflow
        vector<long long> arr(nums.begin(), nums.end());
        long long x = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i-1]) {
                long long diff = arr[i-1] - arr[i];

                //update x if diff
                x += diff;
                //increment whole array with that diff
                for(int j = i; j < n; j++) {

                    arr[j] += diff;
                }
            }
        }
        return x;
    }
};


//OPTIMAL 
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long  x=0;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                long long diff=nums[i-1]-nums[i];
                //update x 
                x+=diff;
            }
        }
        return x;
    }
};
