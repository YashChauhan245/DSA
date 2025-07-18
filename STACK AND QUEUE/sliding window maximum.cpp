https://leetcode.com/problems/sliding-window-maximum/description/
Methods->brute /heaps/deque/sliding window
BRUTE :TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result; 
        for(int i=0;i<=n-k;i++){ //n-k bcz of window ....if i iterates till last element then k is out of bound
            int mxval=nums[i];
            for(int j=i;j<i+k;j++){
                mxval=max(mxval,nums[j]);
            }
            result.push_back(mxval);
        }
        return result;
        
    }
};


APPROACH-2)DEQUE
