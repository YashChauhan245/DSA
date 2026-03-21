https://www.geeksforgeeks.org/problems/attend-all-meetings/1

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        //edge case
        if (arr.size() == 0) return true;
        
        //sort by starting time
        sort(arr.begin(),arr.end());
        
        //now just check overlapping 
        int prev=arr[0][1]; //prev end
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<prev){
                return false;
            }
            prev=arr[i][1];
        }
        return true;
    }
};
