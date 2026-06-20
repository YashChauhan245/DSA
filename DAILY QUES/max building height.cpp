https://leetcode.com/problems/maximum-building-height/description/?envType=daily-question&envId=2026-06-20


//FORMULA: 
// maximum possible height between two adjacent restricted buildings ==>(h1 + h2 + d) / 2

/*
  Example:
id1 = 2, h1 = 1
id2 = 6, h2 = 1

 Distance:
d = 6 - 2 = 4

 Formula:
(1 + 1 + 4) / 2
= 3

One valid arrangement is:
Building: 2 3 4 5 6
Height:   1 2 3 2 1

Peak = 3 
*/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        // Building n can never exceed n - 1
        // (starting from building 1 = 0 and increasing by at most 1 each step).
        restrictions.push_back({n, n - 1});

        // Sort restrictions by building index.
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left-to-right pass:
        // Ensure each restriction is achievable from the previous restriction.
        // Height at current building cannot be greater than:
        // previous_height + distance_between_buildings.
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                restrictions[i][0] - restrictions[i - 1][0]
            );
        }

        // Right-to-left pass:
        // Ensure each restriction is achievable from the next restriction.
        // Height at current building cannot be greater than:
        // next_height + distance_between_buildings.
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                restrictions[i + 1][0] - restrictions[i][0]
            );
        }

        int ans = 0;

        // For every pair of adjacent valid restrictions,
        // compute the highest peak possible between them.
        for (int i = 1; i < m; i++) {

            long long id1 = restrictions[i - 1][0];
            long long h1  = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            // Distance between the two restricted buildings.
            long long d = id2 - id1;

            // Maximum achievable peak between them.
            ans = max(ans, (int)((h1 + h2 + d) / 2));
        }

        return ans;
    }
};
