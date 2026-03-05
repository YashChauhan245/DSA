https://leetcode.com/problems/container-with-most-water/submissions/1938801620/


tc->o(n) and sc o(1)
  
class Solution {
public:
    int maxArea(vector<int>& height) {
       int n=height.size();
       int water=0;
       int i=0;
       int j=n-1;

       while(i<j){
        int w=j-i;
        int h=min(height[i],height[j]);
        int area=h*w;
        water=max(water,area);

        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
       }
       return water;
    }
};
