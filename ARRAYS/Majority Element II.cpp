https://leetcode.com/problems/majority-element-ii/submissions/1674752881/



class Solution {
public:

//Brute force-->using map;

    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int,int>mp;
    //     vector<int>ans;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         mp[nums[i]]++;
    //         if (mp[nums[i]]>n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end()){//finding in vector to avoid duplicates
    //             ans.push_back(nums[i]);
    //         }
    //     } 
    // return ans;    
    // }


//Optimised-->boyre-moore
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0; // initialize with any two different numbers
        int count1 = 0, count2 = 0;

        // First pass: find two potential candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;//for edge cases ..like multiple element in array
                count2--;
            }
        }

        // Second pass: verify actual counts of the two candidates and check >n/3;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) count1++;
            else if (nums[i] == candidate2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};
 
