class Solution {
public:
    int makeboq(vector<int>& bloomDay,int mid, int m, int k){
        int bouqcount=0;
        int consqcount=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consqcount++;
            }
            else{
                consqcount=0;
            }
            if(consqcount==k){
                bouqcount++;
                consqcount=0;
            }
        } 
        return bouqcount;       

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int result=-1;
        int s=0;
        int e=*max_element(begin(bloomDay),end(bloomDay));
        while(s<=e){
            int mid=s+(e-s)/2;
            if(makeboq(bloomDay,mid,m,k)>=m){
                result=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
}; 
