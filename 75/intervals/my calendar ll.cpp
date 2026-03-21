https://leetcode.com/problems/my-calendar-ii/

class MyCalendarTwo {
public:
    map<int, int> mp;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++; //interval start ++
        mp[endTime]--;  //interval end --

        int booking = 0;

        for(auto &it : mp) {
            booking += it.second;

            if(booking > 2) {
              // booking > 2 so cant include that so remove that event to make it neutral(ineffective)
              //basically undo the event from the map 
                mp[startTime]--; 
                mp[endTime]++;
                return false;
            }
        }

        return true;
    }
};
