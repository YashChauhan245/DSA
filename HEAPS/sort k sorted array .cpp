https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int index=0;
        priority_queue<int,vector<int>,greater<int>>minhp;
        for(int i=0;i<arr.size();i++){
            minhp.push(arr[i]);
            if(minhp.size()>k){
                arr[index++]=minhp.top();
                minhp.pop();
            }
        }
        while(!minhp.empty()){
            arr[index++]=minhp.top();
            minhp.pop();
        }
    }
};
