https://leetcode.com/problems/design-event-manager/description/


// Priority queue (Max heap) for storing {eventId, priority} and hashmap to ensure that current eventId maps to current priority, map is updated when updatePriority function is called and the new mapping is pushed to pq

// Custom comparator to sort elements with highest priority first, in case of tie, smaller id elements are placed first


class EventManager {
public:
    struct comp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    unordered_map<int, int> mpp;
    EventManager(vector<vector<int>>& events) {
        for(auto it : events){
            pq.push({it[0], it[1]});
            mpp[it[0]] = it[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({eventId, newPriority});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            pair<int, int> active = pq.top();
            pq.pop();
            int eventId = active.first, priority = active.second;
            if(mpp.count(eventId) && mpp[eventId] == priority){
                mpp.erase(eventId);
                return eventId;
            }
        }
        return -1;
    }
};

