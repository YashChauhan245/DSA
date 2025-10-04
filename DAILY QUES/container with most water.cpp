https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04

//Two pointer Greedy (O(N)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        
        int water = 0;
        while(i<j) {
            
            //start from the smallest one and calculate water
            int h = min(height[i], height[j]);
            int w = j-i;
            int area = h*w;
            water = max(water, area);

          //ignore the smallest one
            if(height[i] < height[j]){
                i++;
            }
            else
                j--;
        }   
        return water;
    }
};
