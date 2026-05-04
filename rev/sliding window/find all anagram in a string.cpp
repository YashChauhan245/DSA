https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=21wyrvm6


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26, 0);
        
        int m = s.length();
        int n = p.length();
        
        for(char &ch : p)
            arr[ch-'a']++; //store freq of p--> 1
        
        int i = 0, j = 0;
        vector<int> result;
        
        while(j < m) {
            arr[s[j] - 'a']--;//freq--
            
            if(j-i+1 == n) { //window size ==n 
                if(arr == vector<int>(26, 0)) { //if freq==0 -->store index
                    result.push_back(i);
                }
                
                arr[s[i]-'a']++; //freq of i ++ & move i 
                i++;
            }
            j++;
        }
        
        return result;
    }
};
