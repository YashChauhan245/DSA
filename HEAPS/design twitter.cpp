https://leetcode.com/problems/design-twitter/description/


/*
Identify What Information Needs to Be Stored
Store Each User’s Tweets
Store Follow Relationships
Maintain a Global Timestamp
Implement postTweet()
Implement follow()
Implement unfollow()
Identify Users for the News Feed
Collect Their Tweets
Use a Max Heap Ordered by Timestamp
Extract the 10 Most Recent Tweets
Return the News Feed
*/

class Twitter {
public:
    
    int timestamp = 0;
    map<int, vector<pair<int, int>>> tweets;//userID-->tweetID,timestamp
    map<int, set<int>> following;  //followerID,followeeID
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;

        tweets[userId].push_back({tweetId, timestamp});
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    
    vector<int> getNewsFeed(int userId) {
        // 1. Get User 1's tweets
        // 2. Get tweets of everyone User 1 follows
        // 3. Put those tweets into a max heap ordered by timestamp
        // 4. Take at most 10 from the heap
         
        priority_queue<pair<int, int>> pq;

        // Add user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push({tweet.second, tweet.first});//tweetID and timestamp
        } 

        // Add tweets of users being followed
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push({tweet.second, tweet.first});
            }
        }

        vector<int> result;

        // Get 10 newest tweets
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

};
