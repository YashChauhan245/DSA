https://leetcode.com/problems/sum-of-two-integers/description/

tc,sc-->both o(1)

// steps:a)sum(xor) b) carry(&) c) new carry (carry<<1) d} repeat all steps till carry become 0
class Solution {
public:
    int getSum(int a, int b) {
        uint32_t carry=a&b;   //so carry must store positive value only
        int sumwithoutcarry=a^b;
        int newcarry=carry<<1;
       //return sumwithout carry if carry 0 
      // else calc till carry becomes zero
        while(carry!=0){
            carry=sumwithoutcarry & newcarry;
            sumwithoutcarry=sumwithoutcarry^newcarry;
            newcarry=carry<<1;
        }
       return sumwithoutcarry; 
    }
};
