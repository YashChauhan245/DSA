https://leetcode.com/problems/minimum-window-substring/


/*approach:
  1)store t in map ----store req_count
  2)expand j and if char in map -->freq-- and count-- ....other element store freq as -1
  3)if count ==0 -->try to min the window for ans by iterating i
  4)if found smaller window store index of that in start variable  to give ans later 
  4)if while min..count again become more than 0-->iterate j again
  5)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";

      // step-1
        unordered_map<char, int> mp;
        for(char c : t) {
            mp[c]++;
        }
       //step-2req count 
        int count = mp.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = 0;  //for min. window substring 

        while(j < n) {
            //step-3...Expand the window
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }

            //step-4... Try to contract the window when all characters matched-->iterate j only if count==0-->if count>0...iterate i 
            while(count == 0) {
                // Update answer if smaller window found 
                if(j - i + 1 < minLen) {  //if current winodw size < min len --->uodate minlen
                    minLen = j - i + 1;
                    start = i;   //smaller window found -->store the inde in start to give ans later
                }

                //agar current ele(i) ko iterate kra meine uska count map me badega 
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                        count++;
                }
                i++; // shrink from left
            } //count>0 -->iterate j
            j++; // expand from right
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
