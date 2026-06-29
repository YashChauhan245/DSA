https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/description/


// Choose one contiguous subarray and modify it (multiply or divide).
// On the resulting array, find the maximum subarray sum.

/*
3 states: normal---operation---normal
before ---> subarray before any operation (original values)
    2 options:
      1. Continue normally        ---> v1 = before + x
      2. Start new subarray       ---> v2 = x

during ---> currently inside the modified subarray
    3 options:
      1. Continue operation       ---> v3 = during + mx
      2. Start operation here     ---> v4 = before + mx
      3. Start new subarray and also start the operation here ---> v5 = mx

after ---> operation has already finished
    3 options:
      1. Continue after operation ---> v6 = after + x
      2. Prev element was still inside the multiplied segmentEnd operation, before this element
       ---> v7 = during + x
      3. Start new subarray       ---> v8 = x  
*/

//BASIC CODE FOR MULTIPLICATION:
    // long long solve(vector<int>& nums, int k) {
    //     const long long NEG = -4e18;

    //     long long before = nums[0];          // no operation started
    //     long long during = 1LL * nums[0] * k; // operation starts here
    //     long long after = NEG;               // impossible initially

    //     long long ans = max({before, during, after});

    //     for (int i -->n) {

    //         long long x = nums[i];
    //         long long mx = 1LL * nums[i] * k;

    //         // Save previous states
    //         long long b = before;
    //         long long d = during;
    //         long long a = after;

    //         // BEFORE
    //         long long v1 = b + x;
    //         long long v2 = x;
    //         before = max(v1, v2);

    //         // DURING
    //         long long v3 = d + mx;
    //         long long v4 = b + mx;
    //         long long v5 = mx;
    //         during = max({v3, v4, v5});

    //         // AFTER
    //         long long v6 = (a == NEG ? NEG : a + x);
    //         long long v7 = d + x;
    //         long long v8 = x;
    //         after = max({v6, v7, v8});

    //         ans = max({ans, before, during, after});
    //     }

    /*To solve the original problem completely
    You need to run the same DP twice:

    mx = nums[i] * k
    mx = divide(nums[i], k) where division follows:
    positive → floor(x / k)
    negative → ceil(x / k)

    Then return:
    max(answerMultiply, answerDivide); */


class Solution {
public:
    long long run(vector<int>& nums, int k, bool multiply) {
        const long long NEG = -(1LL << 60);
        //can do without transform too 
        auto transform = [&](int x) -> long long {
            if (multiply)
                return 1LL * x * k;

            
            else{
                if (x >= 0){
                    return x / k;
                }
                else
                    return -((-x) / k);
            }
        };

        long long before = nums[0];
        long long during = transform(nums[0]); // Modified value-->any be multiply or divide
        long long after = NEG;

        long long ans = max(before, during);

        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long t = transform(nums[i]); 
            // Modified value like mx(2*nums[i]) or dx--> store value instead of operating everyime

            long long b = before;
            long long d = during;
            long long a = after;

            // Before operation
            before = max(b + x, x);

            // During operation
            during = max({d + t, b + t, t});

            // After operation
            after = max({
                (a == NEG ? NEG : a + x),
                d + x,
                x
            });

            ans = max({ans, before, during, after});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k){
        return max(run(nums, k, true), run(nums, k, false));
    }
};

