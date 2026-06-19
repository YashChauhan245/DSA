https://leetcode.com/problems/find-the-highest-altitude/description/?envType=daily-question&envId=2026-06-19


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();

        int maxalt=0;
        int curralt=0;

        for(int i=0;i<n;i++){
            curralt+=gain[i];
            maxalt=max(maxalt,curralt);
        }
        return maxalt;
    }
};
