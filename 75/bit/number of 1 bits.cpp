https://leetcode.com/problems/number-of-1-bits/description/

//how to find binary of any number---->find and store remainder(%) in binary string and replace quotient(/) wuth new n 

//tc-->o(logn)....divide by 2
//sc-->o(1)
class Solution {
public:
    int hammingWeight(int n) {
        int ones=0;
        while(n>0){
            if(n%2==1){  //remainder
                ones++;
            }
            n=n/2;  //quotient
        }
        return ones;
    }
};


optimised->o(k)

class Solution {
public:
    int hammingWeight(int n) {
        int ones = 0;
        while(n){
            n = n & (n - 1);
            ones++;
        }
        return ones;
    }
};
