https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/description/


class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        
        for(int x:nums ){
            string s="";
            while(x>0){
                int power=1;
                int letter=0;

                while(power*2<=x && letter<25){
                    power*=2;
                    letter ++;
                }
                s+=char('a'+letter);
                x-=power;
            }
            ans.push_back(s);
        }
       return ans; 
    }
};
