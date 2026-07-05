https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/description/


class Solution {
public:
    long long maxDigitRange(vector<int>& nums) {
        long long ans=0;
        int maxrange=-1;

        for(int num: nums){
            int temp=num;
            int maxy=0;
            int miny=9;
        
            while(temp>0){
                int digit=temp%10;   //5724 %10=4
                maxy=max(maxy,digit);
                miny=min(miny,digit);
                temp/=10;          //5724/10=572
            }
    
            int range=maxy-miny;
    
            if(range>maxrange){
                maxrange=range;
                ans=num;
            }

            else if (range==maxrange){
                ans+=num;
            }
        }
        return ans;
    }
};
