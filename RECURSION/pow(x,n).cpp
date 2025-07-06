class Solution {
public:
    double powhelper(double x, int n) {
        if(n==0){
            return 1.0;
        }
        if (n == 1) return x;
        // using expo approach as normal approach will give tle 
        double half=powhelper(x,n/2);
        // if n is even 
        if (n % 2 == 0) {
            return half * half;
            // if n is odd
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n){
        long long N = n;  //long long to handle INT_MIN
      // checking for n-->negative
        if (N < 0) {
            return 1.0 / powhelper(x, -N);
        } else {
            return powhelper(x, N);
        }
    }
};
