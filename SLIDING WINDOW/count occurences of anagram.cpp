https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1


class Solution {
  public:
    int search(string &pat, string &txt) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=txt.size();
        int k=pat.size();
        int ans=0;
        if(k>n){
            return 0;
        }
        for(int s=0;s<k;s++){
            mp[pat[s]]++;
        }
        int count=mp.size();
        while(j<n){
            // CALC
            // map me char mil gya 
            if(mp.find(txt[j])!=mp.end()){
                // freq km kro 
                mp[txt[j]]--;
                // if freq==0 -->count --;
                if(mp[txt[j]]==0){
                    count--;
                }
            }
            if(j-i+1<k){
                j++;
            }
            //ANS STORE 
            else if(j-i+1==k){
                // if all the mmatching with pat i.e count should be zero
                if(count==0){
                    ans++;
                }
                
                // SLIDE THE WINDOW
                // if i is in map then freq++;
                if (mp.find(txt[i]) !=mp.end()) {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                        count++;//as count becomes zero previously
                }
                i++;
                j++;
                
            }
            
        }
        return ans;
        
    }
};
