https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/


class Solution {
public:
    bool canShip(vector<int>& weights, int mid, int days) {
        int dayCount = 1;
        int currentLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currentLoad + weights[i] >mid) {
                dayCount++;
                currentLoad = 0;
            }
            currentLoad += weights[i];
        }
        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canShip(weights,mid,days)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
