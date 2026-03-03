https://leetcode.com/problems/two-sum/description/

brute->tc-o(n^2) & sc->o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i, j};    
                }
            }
        } 
        return {},
    }
};


better->o(n) & o(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;//value-index 
        for(int i=0;i<nums.size();i++){
            int ans=target-nums[i];
            if(mp.find(ans)!=mp.end()){ //search number
                return{mp[ans],i}; //index retrun 
            }
            mp[nums[i]]=i; //value-index 

        }
        return {};
    }
};


optimised-> o(nlogn) and o(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Store value along with original index
        vector<pair<int, int>> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        // Sort based on values
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                return {arr[left].second, arr[right].second};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {};
    }
};

