https://leetcode.com/problems/russian-doll-envelopes/description/?envType=study-plan-v2&envId=binary-search


// sort+lis

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort: smaller width first, if width same then bigger height first
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        // LIS using binary search on heights
        vector<int> lis;
        for(auto &e : envelopes){
            int height = e[1];

            // Find correct position to put this height
            int index = lower_bound(lis.begin(), lis.end(), height) - lis.begin();

            // If height is bigger than all in lis, add it
            if(index == lis.size()) {
                lis.push_back(height);
            }
            // Else replace the existing value to keep lis smallest possible
            else {
                lis[index] = height;
            }
        }

        return lis.size();
    }
};
