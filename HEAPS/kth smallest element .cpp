https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1


class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>maxhp;
        for(int i=0;i<arr.size();i++){
            maxhp.push(arr[i]);
            if(maxhp.size()>k){
                maxhp.pop();
            }
        }
        return maxhp.top();
    }
};
