https://leetcode.com/problems/maximize-fixed-points-after-deletions/description/

//Approach- (lis+binary search(lower bound)
class Solution {
public:
    int maxFixedPoints(vector<int>& A) {
        vector<int> s;
        vector<pair<int, int>> B; 

        //step-1--->store those elements that can be reassigned to their original place
        //if index<nums[i]--->cant be rearranged eg 6 in the arr=[1,0,6,1,2,8,7,4,3]
        for (int i = 0; i < A.size(); ++i) {
            if (i >= A[i]) {
                B.push_back({i - A[i], A[i]});//(no of deletions,number)
            }
        }
        sort(B.begin(), B.end());

        //step-2-->LIS with binary search 
        for (auto &p : B) {
            int x = p.second;//original value 

            //  find lower bound of number in ans array->push num in ans(if),else replace with new num
            auto it = lower_bound(s.begin(), s.end(), x);
            if (it == s.end()) {
                // If x is greater than all elements in 's',
                // we extend the LIS
                s.push_back(x);
            } else {
                // Otherwise, replace the element at that position
                // to maintain smallest possible tail for LIS
                *it = x;
            }
        }

        return s.size();
    }
};




