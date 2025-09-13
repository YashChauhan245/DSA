https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=daily-question&envId=2025-09-13


//using freq array
class Solution {
public:
    bool isvowel(char ch){
        ch=tolower(ch);
        if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'|| ch=='u'){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        int freq[26]={0};
        for(char ch:s){ //should use &ch when we are modifying string  inplace 
            freq[ch-'a']++;
        }
        int maxv=0;
        int maxc=0;
        for(int i=0;i<26;i++){
            char ch='a'+i; //int i=0 ->'a'+0=a
            //as we are iterating acc to char
            if(isvowel(ch)){
                maxv=max(maxv,freq[i]);
            }
            else{
                maxc=max(maxc,freq[i]);
            }
        }
        return maxc+maxv;
    }
};


//using map ->char,int



class Solution {
public:
    bool isvowel(char ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        map<char, int> freq;

        // count frequency of characters
        for (char ch : s) {
            freq[ch]++;
        }

        int maxV = 0; // max freq among vowels
        int maxC = 0; // max freq among consonants

        for (auto &mp : freq) {
            char ch = mp.first;
            int count = mp.second;

            if (isvowel(ch)) {
                maxV = max(maxV, count);
            } else {
                maxC = max(maxC, count);
            }
        }

        return maxV + maxC;
    }
};

