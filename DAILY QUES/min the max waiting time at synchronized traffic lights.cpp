https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/description/


class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int maxans=0;
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r=arrivalTime[i] % period;
            if(r <lights[lights.size()-1]){
                continue;
            }
            else{
                ans=abs(period-r);
                maxans=max(ans,maxans);
            }
        }
        return maxans;
    }
};
