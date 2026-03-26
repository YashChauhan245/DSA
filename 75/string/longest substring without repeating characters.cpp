https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


// Brute-->o(n2)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            int hash[256]={0};  //every time i changes -->new hashmap created
            for(int j=i;j<s.size();j++){
                if(hash[s[j]]==1){
                    break;
                }
                hash[s[j]]=1;
                int length=j-i+1;
                maxlen=max(maxlen,length);

            }
        }
        return maxlen;
        
    }
};


// Optimal -->o(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
         int HashLen = 256; 
        int hash[HashLen];
        
        for (int i = 0; i < HashLen; ++i) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
        /* If current character s[r] is already in the substring*/
            if (hash[s[r]] != -1) {
                
            /* Move left pointer to the right of the last occurrence of s[r]*/
                l = max(hash[s[r]] + 1, l);
            }
            
            // Calculate the current substring length
            int len = r - l + 1;
            
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            
            /* Store the index of the current character in the hash table*/
            hash[s[r]] = r;
            
            // Move right pointer to next position
            r++;
        }
       
        // Return the maximum length found
        return maxLen;
    }
};
