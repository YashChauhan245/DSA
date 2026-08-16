https://leetcode.com/problems/maximum-gap-between-stations/description/



class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> left(n);
        vector<int> right(n);

        // Build left[]
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (station[j] != skill[i]) {
                j++;
            }
            left[i] = j;
            j++;
        }

        // Build right[]
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[j] != skill[i]) {
                j--;
            }
            right[i] = j;
            j--;
        }

        // Find maximum gap---> right[i + 1] - left[i] always as what left to be min as min and right as max as max or vice versa
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, right[i + 1] - left[i]);
        }

        return ans;
    }
};
