https://leetcode.com/problems/next-greater-element-i/

// BRUTE -->USING VECTOR AND BOOL VARIABLE 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            bool pushed = false;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                } else if (found && nums2[j] > nums1[i]) {
                    res.push_back(nums2[j]);
                    pushed = true;
                    break;
                }
            }

            if (pushed==false) {
                res.push_back(-1);
            }
        }
        return res;
    }
};


BEST APPRAOCH-->STACK AND MAP 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int size = nums1.size() ;
         vector<int> ans(size,0) ;
         unordered_map<int,int> m ;
         stack<int> st ;
         for(int i=0;i<size ;i++){
             m[nums1[i]]=i ;
         }
         size = nums2.size() ;
         for(int i=size-1 ;i>=0 ;i--){
            if(m.find(nums2[i])!=m.end()){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop() ;
            }
            if(st.empty()){
                ans[m[nums2[i]]]=-1 ;
            }
            if(!st.empty()){
              ans[m[nums2[i]]] = st.top() ;
            }
            }
            st.push(nums2[i]) ;
         }
         return ans ;
    }
};
