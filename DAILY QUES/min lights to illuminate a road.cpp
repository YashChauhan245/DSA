https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/description/


/*BRTUE-->TLE
1.find the non zero elemtn and index
2.calc the range 
3.mark all the elements in the range to 1
4.start from the lefmost:
5.Whenever you find a dark position:
   - Install a new bulb optimally so that it covers as many future
     dark positions as possible (up to 3 positions).
   - bulb_count++
   - Skip the positions covered by that bulb.
*/

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> visible(n, 0);

        // Mark all positions illuminated by existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);

                for (int j = l; j <= r; j++) {
                    visible[j] = 1;
                }
            }
        }

        int ans = 0;

        // Cover remaining dark positions greedily
        for (int i = 0; i < n; ) {
            if (visible[i]!=0) {
                i++;
            } else {
                ans++;
                // // bulb covers current position and next 2 positions
                // i = i + 1; // move past current
                // i = i + 1; // move past next
                // i = i + 1; // move past third position
                i += 3;  // one added bulb covers up to 3 positions
            }
        }

        return ans;
    }
};



//better using difference array ...o(n)

//Instead of making elements to 1 in the range use diffrence array O(1) :
// Instead of updating every element in the range, mark only the start and end+1

/* Update range [2,5]:

diff:
0 0 1 0 0 0 -1 0

Now compute prefix sums:

diff : 0 0 1 0 0 0 -1 0
prefix sum :
0 0 1 1 1 1 0 0  */

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        // Mark coverage of existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
                
                //marks l=1 and r+1=-1
                diff[l]+=1;

                if (r + 1 < n)
                    diff[r + 1]-=1;
            }
        }

        // make visibility array using prefix sum
        vector<int> visible(n, 0);
        int cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];

            if (cur > 0)
                visible[i] = 1;
        }

        // Count additional bulbs greedily
        int ans = 0;

        for (int i = 0; i < n; ) {
            if (visible[i]) {
                i++;
            } else {
                ans++;

                // One new bulb can cover 3 positions
                i += 3;
            }
        }

        return ans;
    }
};

//OPTIMAL -->MERGE INTERVALS O(NLOGN)

/* 
1.create intervals
2.sort by left endpoints
3.merge intervals
4.find gaps -->calc leng and then to find bulbs to add->ceil(l+2/2)
*/

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<pair<int,int>> intervals;

        // Build intervals from existing bulbs
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
                intervals.push_back({l, r});
            }
        }

        // No working bulbs
        if (intervals.empty()) {
            return (n + 2) / 3;
        }

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> merged;

        for (auto &p : intervals) {
            if (merged.empty() || p.first > merged.back().second + 1) {
                merged.push_back(p);
            } else {
                merged.back().second =
                    max(merged.back().second, p.second);
            }
        }

        int ans = 0;

        // Gap before first interval
        if (merged[0].first > 0) {
            int len = merged[0].first;
            ans += (len + 2) / 3;
        }

        // Gaps between intervals
        for (int i = 1; i < merged.size(); i++) {
            int len = merged[i].first - merged[i - 1].second - 1;

            if (len > 0) {
                ans += (len + 2) / 3;
            }
        }

        // Gap after last interval
        if (merged.back().second < n - 1) {
            int len = (n - 1) - merged.back().second;
            ans += (len + 2) / 3;
        }

        return ans;
    }
};

