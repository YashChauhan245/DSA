https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/


class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;//with freq

        for(int &num : nums) {
            int r = ((num % value) + value) % value;//+val)%val--->for negative numbers
            //e.g->(-12%5)-->-2(+5)--->3%5-->3 OR -12+5-->-7+5--->-2+5==3
            mp[r]++;
        }
        int MEX = 0;//as non neg starts from 0--n
        while(mp[(MEX % value)] > 0) {
            mp[(MEX % value)]--;//freq--

            MEX++;//index++
        }
        return MEX;
    }
};
