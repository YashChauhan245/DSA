// class Solution {
// public:

// BRUTE -->o(n3)
//     bool ispalindrome(const string & sub){
//         int l=0;
//         int r=sub.size()-1;
//         while(l<r){
//             if(sub[l]!=sub[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         vector<string>v;
//         int n=s.size();
//         string longest="";
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 string sub=s.substr(i,j-i+1);
//                 if(ispalindrome(sub) && sub.size()>longest.size()){
//                     longest=sub;
//                 }
//             }
//         }
//         return longest;      
//     }
// };


//EXPAND CENTRE APPROACH ....O(N2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        for (int center = 0; center < n; center++) {
            // Odd length palindrome (center at s[center])
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            // Even length palindrome (center between s[center] and s[center+1])
            l = center, r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
