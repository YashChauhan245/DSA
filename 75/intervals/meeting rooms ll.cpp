https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        
        //map-->time,room delta +-
        
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int startPoint = start[i];
            int endPoint   = end[i];
            
            mp[startPoint]++; //room++
            mp[endPoint]--;   //room --
        }
        
        int overlap = 0;
        int maxoverlap = 0;
        
        for(auto& it : mp){
            overlap += it.second; 
            maxoverlap = max(maxoverlap, overlap);
        }
        return maxoverlap;
    }
};


