https://leetcode.com/problems/describe-the-painting/description/

class Solution {
public:
    typedef long long ll;

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, ll> events;

        for(auto& segment : segments) {
            int start = segment[0];
            int end   = segment[1];
            int color = segment[2];

            events[start] += color;
            events[end]   -= color;
        }

        vector<vector<ll>> result;

        auto it = events.begin();
        int start = it->first;
        ll sum = it->second;

        it++;
        while(it != events.end()) {
            if(sum > 0)
                result.push_back({start, it->first, sum});
            
            start = it->first;
            sum  += it->second;
            it++;
        }

        return result;
        
    }
};
