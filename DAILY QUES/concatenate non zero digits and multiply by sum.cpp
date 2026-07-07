https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/


class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long  number=0;
        long long ans=0;

        while(n){
            int digit=n%10;
            if(digit!=0){
                sum+=digit;
                number=number*10+digit;
            }
            n /= 10;
        }

        long long reversed_number=0;

        while(number){
            int digit=number%10;
            if(digit!=0){
                reversed_number=reversed_number*10+digit;
            }
            number /= 10;
        }
        ans=sum*reversed_number;
        return ans;
    }
};
