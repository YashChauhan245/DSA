https://leetcode.com/problems/k-th-digit-in-infinite-string/description/


class Solution {
public:

    // Number of digits from the start of the string
    // through the end of block b.
    long long countDigits(long long b) {

        if (b == 0)
            return 9;

        long long total = 9;

        // Blocks 1...9   -> 2-digit numbers
        // Blocks 10...99 -> 3-digit numbers
        // Blocks 100...999 -> 4-digit numbers
        long long start = 1;
        long long digits = 2;

        while (start <= b) {

            // Last block whose numbers have 'digits' digits.
            long long end = 1;

            for (int i = 0; i < digits - 1; i++)
                end *= 10;

            end--;

            end = min(end, b);

            // Number of blocks in this range.
            long long blocks = end - start + 1;

            // Each block has 10 numbers,
            // each number has 'digits' digits.
            total += blocks * 10 * digits;

            start = end + 1;
            digits++;
        }

        return total;
    }


    int kthDigit(long long k) {

        // Block 0 = 1 2 3 4 5 6 7 8 9
        if (k <= 9)
            return k;

        // 1. Binary search for block b
        long long low = 1;
        long long high = 1000000000000000LL;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countDigits(mid) >= k) {
                // mid could contain k
                high = mid;
            }
            else {
                // k is after mid
                low = mid + 1;
            }
        }

        long long b = low;

        // 2. Find position inside block b

        long long digitsBefore = countDigits(b - 1);

        long long position = k - digitsBefore;


        // 3. Find number of digits per number

        long long firstNumber = 10 * b;

        int d = to_string(firstNumber).size();


        // Convert position to 0-index.
        long long pos = position - 1;

        // 4. Find which number inside the block

        long long numberIndex = pos / d;


        // 5. Find which digit inside that number

        int digitIndex = pos % d;

        // 6. Find actual number

        long long number;

        if (b % 2 == 0) {
            // Even block -> increasing
            number = 10 * b + numberIndex;
        }
        else {
            // Odd block -> decreasing
            number = 10 * b + 9 - numberIndex;
        }

        // 7. Extract required digit
        string s = to_string(number);

        return s[digitIndex] - '0';
    }
};
