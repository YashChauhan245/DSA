https://leetcode.com/problems/find-triangular-sum-of-an-array/submissions/1788615170/

//Approach-1 (Using O(n) space - Do as asked)
//T.C : O(n^2)
//S.C : O(n)

// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         while(nums.size()>1){
//             vector<int>temp;
//             for(int i=0;i<nums.size()-1;i++){
//                 temp.push_back((nums[i]+nums[i+1])%10);
//             }
//             nums=move(temp);
//             // or
//             // nums=temp; -->auto clear
//             // or 
//             // temp.clear();
//         }
//         return nums[0];
//     }
// };



//Approach-2 IN-PLACE--> (O(1) space using two pointers)
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int size = n - 1; size >= 1; size--) {

            for (int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            
        }
        return nums[0];
    }
};

