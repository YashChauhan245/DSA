https://leetcode.com/problems/palindrome-pairs/description/


/**
3 Cases:
    1. string reverse:
            word1 = "abcd"
            reverse(word1) = "dcba" (present in map)
            "abcd" + "dcba" = "abcddcba"
    2.empty string :
            "aa"+""=aa
    3.tricky:
        word1 = "aaed"
        word2 = "de"
        concatenated string="ed-aa-de"
*/

class Solution {
public:

    vector<vector<int>> palindromePairs(vector<string>& words) {

        vector<vector<int>> ans;
        unordered_map<string, int> mp;


        // store word -> index
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }


        for (int i = 0; i < words.size(); i++) {

            string word = words[i];

            for (int cut = 0; cut <= word.size(); cut++) {


                // CASE 1:
                // firstPart is palindrome
                //
                // word = "ll|s"
                //
                // word2 = reverse("s") = "s"
                //
                // word2 + word
                // "s" + "lls" = "slls"

                if (isPalindrome(word, 0, cut - 1)) { //left side

                    string word2 = word.substr(cut);
                    reverse(word2.begin(), word2.end());

                    if (mp.count(word2) && mp[word2] != i) {

                        ans.push_back({mp[word2], i});
                    }
                }



                // CASE 2:
                // secondPart is palindrome
                //
                // word = "ab|c"
                //
                // word2 = reverse("ab") = "ba"
                //
                // word + word2
                // "abc" + "ba" = "abcba"

                if (cut != word.size() && isPalindrome(word, cut, word.size() - 1)) {

                    string word2 = word.substr(0, cut);
                    reverse(word2.begin(), word2.end());

                    if (mp.count(word2) && mp[word2] != i) {

                        ans.push_back({i, mp[word2]});
                    }
                }
            }
        }

        return ans;
    }


    bool isPalindrome(string &s, int l, int r) {

        while (l < r) {

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
