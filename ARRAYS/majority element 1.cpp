//https://leetcode.com/problems/majority-element/submissions/1672582652/


class Solution {
public:
    int majorityElement(vector<int>& nums) {

// Brute force:...map (TC,SC-->o(n))

//         unordered_map<int,int>mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[num[i]]++;
//             if (mp[nums[i]]>n/2){
//                 return nums[i];
//             }
//         } 
//     return -1;

// optimised-->boyer-morre ...(sc-0(N))
    int count = 0;
    int candidate = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
        }

        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
    }
};
