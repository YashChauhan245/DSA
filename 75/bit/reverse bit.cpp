https://leetcode.com/problems/reverse-bits/description/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i = 0; i < 32; i++) {
            ans <<= 1;          //left shift every bit 
            ans |= (n & 1);    //find right most bit 
            n >>= 1;            //right shift
        }

        return ans;
    }
};
