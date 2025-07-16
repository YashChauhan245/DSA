https://leetcode.com/problems/asteroid-collision/description/

BRUTE APPROACH-->slightly hard to implement..

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int ast = asteroids[i];
            bool destroyed = false;

            // Check for collisions
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop();  // right asteroid destroyed
                } else if (st.top() == -ast) {
                    st.pop();  // both destroy
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  //when st.top >arr[i]
                    break;
                }
            }

            if (!destroyed) {
                st.push(ast);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};


APPROACH-2)
