https://leetcode.com/problems/circle-and-rectangle-overlapping/description/?envType=daily-question&envId=2026-09-19



class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,int x1, int y1, int x2, int y2) {
        
        // Find closest x-coordinate in rectangle
        int closestX;

        if (xCenter < x1)
            closestX = x1;
        else if (xCenter > x2)
            closestX = x2;
        else
            closestX = xCenter;

        // Find closest y-coordinate in rectangle
        int closestY;

        if (yCenter < y1)
            closestY = y1;
        else if (yCenter > y2)
            closestY = y2;
        else
            closestY = yCenter;


        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        int distance = dx * dx + dy * dy;

        return distance <= radius * radius;
    }
};
