https://leetcode.com/problems/fruit-into-baskets/description/

APPROACH-1)T.C->0(N)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int n=fruits.size();
        int maxlen=0;
        int len=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                    // decreasing freq
                mp[fruits[l]]--;
                //if freq=0 -->remove element from map
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
        
    }
};

