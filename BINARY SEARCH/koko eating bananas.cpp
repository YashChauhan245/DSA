class Solution {
public:
    bool caneat(vector<int>& piles,int mid,int h){
        int actual_hrs=0;
        for (int i = 0; i < piles.size(); i++) {
            actual_hrs += piles[i] / mid;
            if (piles[i] % mid != 0) {
                actual_hrs++;
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
