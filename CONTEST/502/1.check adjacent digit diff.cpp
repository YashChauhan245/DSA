https://leetcode.com/problems/check-adjacent-digit-differences/description/

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        bool ans=true;
        for(int i=1;i<n;i++){
            if(abs(s[i]-s[i-1])>2){
                return false;
            }
        }
        return true;
    }
};
