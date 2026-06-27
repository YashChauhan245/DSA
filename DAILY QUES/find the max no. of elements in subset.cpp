https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27


/*
Step 1: Count the frequency of every number in the array using a hash map.
Step 2: Initialize the answer as 1 because a single element always forms a valid subset.
Step 3: Iterate through every unique number in the frequency map and assume it is the starting value x.
Step 4: Set:
curr = x
length = 0

Step 5: Check whether the current number has at least 2 occurrences.
If yes, it can be placed on both the left and right sides of the palindrome.
Increase length by 2.

Step 6: Move to the next number in the chain by squaring the current number.
curr = curr × curr

Step 7: Repeat Steps 5 and 6 as long as the current number exists and has a frequency of at least 2.

Step 8: When you can no longer continue the chain:
If the current number exists at least once, use it as the center of the palindrome.
Increase length by 1.

Step 9: Update the maximum answer with the current length.
Step 10: Repeat Steps 3–9 for every unique number in the frequency map.
Step 11: Handle the number 1 separately because:
1² = 1 As,The chain would never end. 
*/


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        // Store frequency of every number
        unordered_map<long long, int> freq;
        for (int x : nums)
            freq[x]++;

        // Min possible answer is 1
        int ans = 1;

        // Try every unique number as the starting value x
        for (auto &[num, cnt] : freq) {

            // Special case for 1
            // Since 1^2 = 1, it forms an infinite chain.
            // We can use the largest odd number of 1's.
            if (num == 1) {
                if (cnt % 2 == 0)
                    ans = max(ans, cnt - 1);
                else
                    ans = max(ans, cnt);
                continue;
            }

            long long curr = num;
            int len = 0;

            // Keep extending the chain:
            // num -> num^2 -> num^4 -> ...
            while (freq.count(curr) && freq[curr] >= 2) {  //f.count() return 1 if element present

                // Current value can appear on both sides
                // of the palindrome.
                len += 2;

                // Prevent overflow before squaring
                if (curr > 1000000000LL / curr){
                    curr=-1;
                    break;
                }

                curr = curr * curr;
            }

            // If current value exists at least once,
            // it can become the center element.
            if (freq.count(curr))
                len++;
            else if (len > 0)
                len--;          // No center found, remove one side


            ans = max(ans, len);
        }

        return ans;
    }
};
