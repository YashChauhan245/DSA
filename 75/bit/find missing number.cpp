https://www.geeksforgeeks.org/dsa/find-the-missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        for(int i = 0; i<nums.size(); i++) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
};



// Approach-2 (math)
    sum of indexes of arr till - total sum of array


//Approach-3 (Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l   = 0;
        int r   = n-1;
        int result = n;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > mid) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
        
    }
};
