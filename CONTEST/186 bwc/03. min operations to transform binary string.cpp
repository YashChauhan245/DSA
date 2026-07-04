https://leetcode.com/problems/minimum-operations-to-transform-binary-string/description/


class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int ans = 0;
        int i = 0;

        while(i < n){

            if(s1[i] == s2[i]){
                i++;
                continue;
            }

            // 0 -> 1
            if(s1[i]=='0' && s2[i]=='1'){
                ans++;
                i++;
            }

            // 1 -> 0 block
            else{
                int start = i;

                while(i<n && s1[i]=='1' && s2[i]=='0'){
                    i++;
                }

                int len = i-start;

                ans += len/2;  //even block

                if(len%2){  //for odd block now one '1' is left so just convert neighbour and apply operation 2
  
                    // single character string impossible
                    if(n==1)
                        return -1;

                    ans += 2;//2 operations-->0 to 1 && pair operation 
                }
            }
        }

        return ans;
    }
};
