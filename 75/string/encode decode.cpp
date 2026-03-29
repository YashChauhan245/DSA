https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

class Solution {
  public:
    string encode(vector<string>& s) {
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            string str = s[i];
            result += to_string(str.size())+'#'+str;
        }
        return result;
    }

    vector<string> decode(string& s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            
            // iterate j till #
            while (s[j] != '#') {
                j++;
            }
            
            // extract legnth(size) and convert string to integer
            int len = stoi(s.substr(i, j - i));
            
            // Expand the word from j to len
            string word = s.substr(j + 1, len);
            result.push_back(word);
            
            //update i
            i = j + 1 + len;
        }
        
        return result;
    }
};
