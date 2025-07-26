https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0,h=m;
        int mid=l+(h-l)/2;
        while(l<=h){
            // px -->nums 1 ke kitne element mujhe left me chaiye 
            int px=(l+h)/2;//mid
            // py-->nums 2 ke kitne elemnet mujhe left me chaiye 
            int py=((m+n+1)/2)-px;

            int l1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int l2 = (py == 0) ? INT_MIN : nums2[py - 1];
            int r1 = (px == m) ? INT_MAX : nums1[px];
            int r2 = (py == n) ? INT_MAX : nums2[py];
            if(l1<=r2 && l2<=r1){
                if((n+m)&1){
                    return max(l1,l2);
                }
                else{
                    int a=max(l1,l2);
                    int b=min(r1,r2);
                    return (a+b)/2.0;
                }
            }
            else if(l1>r2){
                // l1 bda h means l1 me jyda element hai ...so km kro element (and nums1 sorted hai so high--)
                h=px-1;
            }
            else{
                // needs bda element so l++ , taki koi jyda value wala element aa paye bcz nums1 sorted hai 
                l=px+1;
            }
        }
        return 0.0;
    }
};
