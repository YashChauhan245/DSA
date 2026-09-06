https://leetcode.com/problems/count-robot-groups/description/



class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        stack<pair<long long,long long >>st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({position[i],speed[i]});
                    continue;
            }
            long long  groupPos=st.top().first;
            long long  groupSpeed=st.top().second;

            //merge and dont add it in stack 
            if(groupPos-position[i]<=distance || speed[i]>groupSpeed){
                st.pop();
                st.push({position[i],groupSpeed}); //push updated group
            }
            else{
                st.push({position[i],speed[i]});
            }

        }
        return st.size();
    }
};
