https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> visited(100000, 0);

        q.push({start, 0});
        visited[start] = 1;

        while (!q.empty()) {
            int num = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (num == end) return steps;

            for (int i = 0; i < arr.size(); i++) {
                int newNum = (num * arr[i]) % 100000;

                if (!visited[newNum]) {
                    visited[newNum] = 1;
                    q.push({newNum, steps + 1});
                }
            }
        }

        return -1;
    }
};
