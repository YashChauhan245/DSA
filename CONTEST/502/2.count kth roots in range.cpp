https://leetcode.com/problems/count-k-th-roots-in-a-range/description/

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        auto t = make_tuple(l, r, k);
        int first = ceil(pow(l, 1.0 / k) - 1e-9);
        int last  = floor(pow(r, 1.0 / k) + 1e-9);

        if (last < first) return 0;

        return last - first + 1;
    }
};
