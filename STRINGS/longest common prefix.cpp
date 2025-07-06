https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs.front();
        string last=strs.back();
        int minlength=min(first.size(),last.size());
        int i=0;
        while(i<minlength){
            if (first[i]==last[i]){
                i++;
            }
            else{
                break;
            }
        }
    return first.substr(0,i);
    }
};
