https://leetcode.com/problems/insert-interval/


BRUTE-->TLE  o(n2) -->while loop and then shifting and merge 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size()){
            // jis interval pe hu uska ending pt <newinterval ke start se 
            if(intervals[i][1]<newInterval[0]){
                i++;
            }
            // if interval ka starting >newinterval ke ending 
            else if(intervals[i][0]>newInterval[1]){
                // insert before that i ;
                // kha krna h insert and kise krna h
                intervals.insert(intervals.begin()+i,newInterval);
                return intervals;
            }
            else{ //(intervals[i][1]>newinterval[0])
                // merge and delete and update new interval;
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                // erase;
                intervals.erase(intervals.begin()+i); 
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};



APPROACH-2)optimal


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                // breaks and push remaing in ans;
                // ans.push_back(newInterval); --->not pushing here bcz if array is empty ..we have to use newinterval in ans...but in this loop its not possible 
                break;
            }
            else{
                // merge
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
            }
            i++;
        }
        ans.push_back(newInterval);
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }
};
