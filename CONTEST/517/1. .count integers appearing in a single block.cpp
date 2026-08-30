https://leetcode.com/problems/count-integers-appearing-in-a-single-block/description/


class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int ans=0;

        for(int x:s){
            int first=-1;
            int last=-1;
            int count=0;

            for(int i=0;i<nums.size();i++){
                if(nums[i]==x){
                    if(first==-1){
                        first=i;
                    }
                    last=i;
                    count++;
                }
            }
            if(last-first+1==count){
                ans++;
            }
        }
        return ans;
    }
};
