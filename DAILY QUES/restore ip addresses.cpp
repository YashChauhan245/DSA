https://leetcode.com/problems/restore-ip-addresses/description/



class Solution {
public:
    int n;
    vector<string> result;
    
    bool isValid(string str) {
        if(str[0] == '0')
            return false;
        
        int val = stoi(str);
        
        if(val <= 255){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(string& s, int idx, int part, string curr) {
        if(idx == n && part == 4) {
            result.push_back(curr.substr(0, curr.length()-1));
            return;
        }
        
        //1-2-3 digits in 1 part
        if(idx+1 <= n)
            solve(s, idx+1, part+1, curr + s.substr(idx, 1) + ".");
        
        if(idx+2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, idx+2, part+1, curr + s.substr(idx, 2) + ".");
        }
        
        if(idx+3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, idx+3, part+1, curr + s.substr(idx, 3) + ".");
        }
    }
    

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        n = s.length();
        
        if(n > 12)
          return result;
      
        int part = 0;
        string curr = "";
        
        solve(s, 0, part, curr);
        return result;
        
    }
};
