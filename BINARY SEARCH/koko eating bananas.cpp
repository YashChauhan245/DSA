https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    bool caneat(vector<int>& piles,int mid,int h){
        int actual_hrs=0;
        for (int i = 0; i < piles.size(); i++) {
            actual_hrs += piles[i] / mid;   //  7/3=2
            if (piles[i] % mid != 0) {      //7%3=1
                actual_hrs++;             //total =3;
            }
        }
        return actual_hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int high=*max_element(begin(piles),end(piles));
        while(l<high){
            int mid=l+(high-l)/2;//mid is the no. of bananas she can eat per hour
            if (caneat(piles,mid,h)){
                high=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
