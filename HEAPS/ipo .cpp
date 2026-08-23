https://leetcode.com/problems/ipo/description/


/*
->Sorted array by capital
->find all affordable projects
->Max Heap
->maximum profit
->w++
->repeat
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap; //profit

        int i = 0;

        for (int j = 0; j < k; j++) {
            // Add all currently affordable projects
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // No project can be done
            if (maxHeap.empty()) {
                break;
            }

            // Choose maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
