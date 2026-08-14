https://leetcode.com/problems/most-popular-video-creator/description/


class Solution { 
public: 
    vector<vector<string>> mostPopularCreator(vector<string>& creators,vector<string>& ids,vector<int>& views) { 
        unordered_map<string, pair<long long, pair<int, string>>> mp;
        // {creator -> {totalViews, {bestViews, bestId}}}

        for (int i = 0; i < creators.size(); i++) { 
            string creator = creators[i]; 
            string id = ids[i]; 
            int view = views[i]; 

            if (!mp.count(creator)) {
                mp[creator] = {0, {-1, ""}};
            }

            // Add current video's views to total popularity
            mp[creator].first += view; 

            // Update best video
            if (view > mp[creator].second.first) { 
                mp[creator].second.first = view; 
                mp[creator].second.second = id; 
            } 
            else if (view == mp[creator].second.first) { 
                
                // If views are equal, choose lexicographically smaller ID
                if (id < mp[creator].second.second) { 
                    mp[creator].second.second = id; 
                } 
            } 
        } 

        // Find maximum popularity
        long long maxPopularity = 0; 

        for (auto& [creator, data] : mp) { 
            maxPopularity = max(maxPopularity, data.first); 
        } 

        vector<vector<string>> ans; 

        for (auto& [creator, data] : mp) { 
            if (data.first == maxPopularity) { 
                ans.push_back({creator, data.second.second}); 
            } 
        } 

        return ans; 
    } 
};
