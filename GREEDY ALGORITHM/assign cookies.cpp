https://leetcode.com/problems/assign-cookies/submissions/1708826920/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=0;
        int j=0;
        while(j<s.size() && i<g.size()){
            if(s[j]>=g[i]){
                j++;
                i++;
            }
            else if(s[j]<g[i]){
                j++;
            }
        }
        return i;

    }
}; 
