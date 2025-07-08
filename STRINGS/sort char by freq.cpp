https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>v;
        int freqtable[256]={0};
        for(int i=0;i<s.length();i++){
            freqtable[s[i]]++;
        }  
        for(int i=0;i<256;i++){
            if(freqtable[i]>0){
                v.push_back({(char)i,freqtable[i]});
            }
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        string result ="";
        for(auto it=v.begin();it!=v.end();it++){
            result.append(it->second,it->first);
        }
        return result;
    }
};
