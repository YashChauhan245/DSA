https://leetcode.com/problems/maximum-xor-product/description/


https://www.youtube.com/watch?v=rCnELsv6L2I

//Approach-1 (Brute Force) - OVERFLOW
//T.C : O(2^n)
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int result = 0;
        
        for(int x = 0; x < pow(2, n); x++) {
            long long p = (a^x) * (b^x);
            result = max<long long>(result, p);
        }
        
        return result;
    }
};

//Approach-2 (Building bit by bit) - Always solve such Qns bit by bit
//T.C : O(n) for loop
class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {

        ll xXora = 0;
        ll xXorb = 0;
        /*
            0 <= a, b < 2^50
            So, a and b will be represented by 50 bits only (0th bit to 49th bit)
            Now, what if x value is something which can be represented by only say 3 bits
            So, x = 0000000000000......11 (50 bits)
            So, let's say a = 101......000000000001 (50 bits)
                          x = 0000000000000......11 (50 bits, but only starting 2 bits matter)
            
            Now, notice that for a^x, From 49th bit to nth bit will be same as what is present in 'a'
            Hence the extra for loop below takes care of that
        */
        for(long long i = 49; i >= n; i--) {
            bool aset = (a >> i) & 1 > 0; //Finding the ith bit of a
            bool bset = (b >> i) & 1 > 0; //Finding the ith bit of b

            if(aset)
                xXora ^= (1ll << i);
            if(bset)
                xXorb ^= (1ll << i);
        }

        /*
            Given constraint : n = 0 to 50
            So, x = 2^0 to 2^50
            2^50 = 1000000000.......0 (total 50 bits from 0th bit in right to 49th i.e. (n-1)th bit in left)
            So, we will check from (n-1)th bit of a and b as well along with x formation
        */
        for (long long i = n-1; i >= 0; i--) {
            
            bool aset = (a & (1ll << i)) > 0; //Finding the ith bit of a
            bool bset = (b & (1ll << i)) > 0; //Finding the ith bit of b

            //If both ith bit of a and b are same
            if(aset == bset) {
                xXora ^= (1ll << i);
                xXorb ^= (1ll << i);
                continue;
            }
            
            if(xXora > xXorb) {
                xXorb ^= (1ll << i);
            } else {
                xXora ^= (1ll << i);
            }

        }   

        xXora %= M;
        xXorb %= M;
        return (xXora * xXorb) % M;
    }
};
