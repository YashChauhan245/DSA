https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/description/

class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int reverseNumber(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
    int sumOfPrimesInRange(int n) {
        int r=reverseNumber(n);
        int sum=0;
        int L=min(n,r);
        int R=max(n,r);

        for (int i = L; i <=R; i++) {
            if (isPrime(i)) {
                sum+=i;
            }
        }
        return sum;
    }
};
