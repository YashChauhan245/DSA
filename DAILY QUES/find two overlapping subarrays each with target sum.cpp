https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/?envType=daily-question&envId=2026-09-17



class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;

        vector<int> best(n, INT_MAX);

        int shortest = INT_MAX;
        int answer = INT_MAX;

        while (j < n) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i];
                i++;
            }

            if (sum == target) {
                int len = j - i + 1;
                // Check for a previous non-overlapping subarray
                if (i > 0 && best[i - 1] != INT_MAX) {
                    int total = len + best[i - 1];
                    answer = min(answer, total);
                }

                // Remember the shortest subarray found so far
                shortest = min(shortest, len);
            }

            // Store shortest valid subarray till j
            best[j] = shortest;
            j++;
        }

        if (answer == INT_MAX) {
            return -1;
        }
        return answer;
    }
};
