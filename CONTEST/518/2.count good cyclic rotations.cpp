https://leetcode.com/problems/count-good-cyclic-rotations/description/

// rightsidesum=total-leftside
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int half=n/2;

        long long total=0;
        //total sum
        for(int num:nums){
            total+=num;
        }

        //1st half sum for 0th rotation

        long long firstsum=0;
        for(int i=0;i<half;i++){
            firstsum+=nums[i];
        }

        int ans=0;

        //check for all rotation 0-n
        for(int i=0;i<n;i++){
            if(firstsum>total-firstsum){
                ans++;
            }
            firstsum-=nums[i];
            firstsum+=nums[(i+half)%n];
        }
        return ans;
    }
};
