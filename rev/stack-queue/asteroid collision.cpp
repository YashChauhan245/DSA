https://leetcode.com/problems/asteroid-collision/description/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            if (asteroids[i] > 0) {
                st.push(asteroids[i]);  // positive push 
            } 
            else {
                int curr = asteroids[i];

                while (!st.empty() && st.top() > 0) {
                    if (abs(st.top()) < abs(curr)) {
                        st.pop();       // top destroyed
                    } 
                    else if (abs(st.top()) == abs(curr)) {
                        st.pop();       // both destroyed
                        curr = 0;
                        break;
                    } 
                    else {
                        curr = 0;       // current destroyed as it was smaller 
                        break;
                    }
                }
                if (curr != 0) {
                    st.push(curr);      // survived
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
