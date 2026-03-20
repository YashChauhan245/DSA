https://leetcode.com/problems/insert-interval/



//brute ->o(n2) bcz of shifting due to erase as shifting is o(n) + o(n) normal iteration 

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int i=0;

//         while(i<intervals.size()){
//             //1st case
//             if(intervals[i][1]<newInterval[0]){
//                 i++;
//             }

//             //2nd case
//             else if(intervals[i][0]>newInterval[1]){
//                 //insert newinterval in intervals and return 
//                 intervals.insert(intervals.begin()+i,newInterval);
//                 return intervals;
//             }

//             else{
//                 //overlap->merge and erase i and update new interval
//                 newInterval[0]=min(newInterval[0],intervals[i][0]);
//                 newInterval[1]=max(newInterval[1],intervals[i][1]);
//                 // erase
//                 intervals.erase(intervals.begin()+i); 
//             }
//         }
//         //edge case ( [1,2][3,4] and new interval[10,12])
//         intervals.push_back(newInterval);
//         return intervals;
//     }
// };


//optimised ->o(n) but space o(n) to avoid tc due to shifting 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                //store in result
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;//ans found so just break and insert remaining intervals in result array using while loop
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        //edge case
        result.push_back(newInterval);
        //inserting remaining intervals in result
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};



