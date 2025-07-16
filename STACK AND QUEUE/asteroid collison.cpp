https://leetcode.com/problems/asteroid-collision/description/

BRUTE APPROACH-->using stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int ast = asteroids[i];
            bool destroyed = false;// or can use ast=0 ....as used it vector

            // Check for collisions
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop();  // arr[i]>st.top()
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


APPROACH-2)using vector as stack 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;  // using vector

        for (int i = 0; i < asteroids.size(); i++) {
            int ast = asteroids[i];

            while (!result.empty() && ast < 0 && result.back() > 0) {
                if (result.back() < abs(ast)) {
                    result.pop_back();  // arr[i]>st.top()
                    continue;
                } else if (result.back() == abs(ast)) {
                    result.pop_back();  //both destroy
                    ast=0;//marks asteroid as destroyed
                    break;
                } else {
                    //v.back()>arr[i]
                    ast=0;//marks asteroid as destroyed
                    break;
                }
            }

            if (ast!=0) {
                result.push_back(ast);  //arr[i] is positive..just push in vector
            }
        }

        return result;
    }
};

