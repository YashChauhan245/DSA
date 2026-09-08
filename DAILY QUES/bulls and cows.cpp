https://leetcode.com/problems/bulls-and-cows/description/



class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;

        map<char, int> secretMap; //char,freq
        map<char, int> guessMap;


        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            else {
                secretMap[secret[i]]++; //107
                guessMap[guess[i]]++;   //710  
            }          
        }

        // Find cows
        for (auto it : guessMap) {  //710
            char digit = it.first;
            if (secretMap.find(digit) != secretMap.end()) {
                cow += min(secretMap[digit], guessMap[digit]); //counter duplicates testcase-2
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
