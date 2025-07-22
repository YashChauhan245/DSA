https://leetcode.com/problems/hand-of-straights/description/

//Approach (Simply using map)
//T.C  : O(nlogn) + O(n*groupSize)
//S.C  : O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize) {
            return false;
        }

        map<int, int> mp;
        for(int &handNumber : hand) {
            mp[handNumber]++; //O(nlogn)
        }

        while(!mp.empty()) { //O(n*groupSize)

            int curr = mp.begin()->first; //->second : frequency

            for(int i = 0; i < groupSize; i++) {
                if(mp[curr + i] == 0) {
                    return false;
                }

                mp[curr+i]--;
                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }

        }

        return true;
        
    }
};



Approach-2)map +heap

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for(int card : hand) {
            freq[card]++;
        }
        // Min-heap to always get the smallest available card
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto it: freq) {
            minHeap.push(it.first);
        }
        while(!minHeap.empty()) {
            int start = minHeap.top();  // smallest available card
            // Try to build a group starting from 'start'
            for(int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if(freq[curr] == 0) return false;
                freq[curr]--;
                if(freq[curr] == 0) {
                    // Only remove from heap if it's at the top (minHeap doesn't support erase)
                    if(curr == minHeap.top()) {
                        minHeap.pop();
                    }
                }
            }
            // Clean up top elements with 0 freq
            while(!minHeap.empty() && freq[minHeap.top()] == 0) {
                minHeap.pop();
            }
        }
        return true;
    }
};
