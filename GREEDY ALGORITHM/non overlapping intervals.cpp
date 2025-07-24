https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // Sort by end time
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        // storing ending pt. of 1st interval
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                count++;
            }
            else{
                // endpt update
                end=intervals[i][1];
            }
        }
        return count;
    }
};
