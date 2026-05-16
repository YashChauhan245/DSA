https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/description/


class Solution {
public:

    bool isprime(int num){
        if(num<=1){return false;}
        for(int i=2;i*i<=num;i++){
            if(num%i==0){return false;}
        }
    return true;
    }

    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n;i++){
            if(i%2==0){ //even index 
                if(isprime(nums[i])){ //prime 
                    continue;
                }
                else{
                    int no=nums[i];
                    //its not prime so increment num & ops until it becomes prime
                    while(!isprime(no)){
                        no++;
                        ops++;
                    }
                }
            }
            else{
                //odd index && no prime
                if(isprime(nums[i])==false){continue;}
                else{
                    int no=nums[i];
                    while(isprime(no)==true){
                        no++;
                        ops++;
                    }
                }
            }
        }
    return ops;
    }
};
