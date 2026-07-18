https://leetcode.com/contest/biweekly-contest-187/problems/minimum-adjacent-swaps-to-partition-array/description/


class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD= 1e9+7;
        long long count0=0,count1=0, count2=0;
        long long ans=0;

        for(int num:nums){
            int part;
        //divide all elements acc to parts/labels
            if(num<a){
                part=0;
            }
            else if(num<=b){
                part=1;
            }
            else part=2;

            //step-2 assign 
            if(part==0){
                ans=(ans+count1+count2)%MOD;
            }
            else if(part==1){
                ans=(ans+count2)%MOD;
            }

            if(part==0){
                count0++;
            }
            else if(part==1){
                count1++;
            }
            else{
                count2++;
            }
        }
        return (int)(ans%MOD);
    }
};©leetcode
