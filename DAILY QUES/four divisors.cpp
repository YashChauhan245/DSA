https://leetcode.com/problems/four-divisors/description/


class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) 
        {
            int cnt = 0;
            int sum = 0;
            for (int i = 1; i <= sqrt(n); i++) 
            {
                if (n % i == 0) 
                {
                    int j = n / i;
                    if (i == j) 
                    {
                        cnt++;
                        sum += i;
                    } 
                    else 
                    {
                        cnt += 2;
                        sum += i + j;
                    }
                }
                if (cnt > 4) break; 
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};
