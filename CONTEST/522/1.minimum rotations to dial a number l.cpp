https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/description/



class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int curr=0;
        for(char c:s){
            int next=c-'0';
            int diff=abs(curr-next);
            ans=ans+min(diff,10-diff);
            curr=next;   
        }
        return ans;
    }
};
