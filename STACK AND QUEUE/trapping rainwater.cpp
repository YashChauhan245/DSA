https://leetcode.com/problems/trapping-rain-water/

APPROACH-1)using array ....
T-C->0(3N)
S.C->0(2N) 2 vector used 
class Solution {
public:
    vector<int> computeLeftMax(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    vector<int> computeRightMax(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        vector<int> leftMax = computeLeftMax(height);
        vector<int> rightMax = computeRightMax(height);

        int total = 0;
        for (int i = 0; i < height.size(); ++i) {
            total += min(leftMax[i], rightMax[i]) - height[i];
        }
        return total;
    }
};




APPROACH-2)2 POINTERS...

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0;
        int rightmax=0;
        int  ans=0;
        int l=0;
        int r=n-1;
        while(l<r){
            leftmax=max(leftmax,height[l]);
            rightmax=max(rightmax,height[r]);
            if(leftmax<rightmax){
                ans+=leftmax-height[l];
                l++;
            }
            else{
                ans+=rightmax-height[r];
                r--;
            }
        }
        return ans;
        
    }
};
