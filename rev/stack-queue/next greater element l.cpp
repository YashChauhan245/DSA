https://leetcode.com/problems/next-greater-element-i/description/


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
