https://leetcode.com/problems/angles-of-a-triangle/description/


class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        //sort all the sides
        sort(sides.begin(), sides.end());

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        // Triangle validity check
        if (a + b <= c) {
            return {};
        }

        vector<double> ans;
        //formula-->to find angles using Law of Cosines

        // Angle opposite to side a
        double A = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI;
        // Angle opposite to side b
        double B = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI;
        // Angle opposite to side c
        double C = acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / M_PI;

        ans.push_back(A);
        ans.push_back(B);
        ans.push_back(C);

        return ans;
    }
};
