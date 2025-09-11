https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11



//APPROACH -1 )
//T.C->NLOGN
//S.C->0(K)

class Solution {
public:
    // Helper function to check vowels
    // bool isVowel(char c) {
    //     return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
    //            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    // }
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string sortVowels(string s) {
        vector<char> vowelsList;

        // Step 1: Collect vowels
        for (char c : s) {
            if (isVowel(c)) {
                vowelsList.push_back(c);
            }
        }

        // Step 2: Sort vowels
        sort(vowelsList.begin(), vowelsList.end());

        // Step 3: Replace vowels in string
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowelsList[j++];
            }
        }
        return s;
    }
};




//Approach -2)
// T.C->O(N)


class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        //storing vowels for string in map
        for(char &ch : s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        } 
        string temp   = "AEIOUaeiou";
        int j = 0; //pointing to temp (current vowel)
        for(int i = 0; i<s.length(); i++) {
            if(isVowel(s[i])) {
               //replacing with the smallest vowel present in the  map 
                while(mp[temp[j]] == 0) {
                    j++;
                }  
                s[i] = temp[j];
                mp[temp[j]]--;
            } 
        }
        return s; 
    }
};
