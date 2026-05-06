https://leetcode.com/problems/sort-vowels-by-frequency/description/

class Solution {
public:

    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string sortVowels(string s) {

        unordered_map<char,int> freq;
        unordered_map<char,int> first;

        // 1)frequency + first occurrence
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                freq[s[i]]++;
                if(first.find(s[i]) == first.end()){
                    first[s[i]] = i;
                }
            }
        }

        // 2)store vowels from string
        vector<char> v = {'a','e','i','o','u'};

        // 3) sort vowel string according to condition
        sort(v.begin(), v.end(), [&](char a, char b){
            //freq
            if(freq[a] != freq[b]){
                return freq[a] > freq[b];
            }
            //position
            return first[a] < first[b];
        });

        //4) make final sorted vowel string
        string temp = "";
        for(char ch : v){
            while(freq[ch]--){
                temp += ch;
            }
        }

        //5) replace vowels
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};
