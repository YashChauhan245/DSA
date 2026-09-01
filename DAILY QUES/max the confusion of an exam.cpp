https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/?envType=problem-list-v2&envId=dlab054g


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0;
        int freqT = 0, freqF = 0;
        int ans = 0;

        for (int r = 0; r < answerKey.size(); r++) {
            if (answerKey[r] == 'T')
                freqT++;
            else
                freqF++;

            // Operations needed = minority count
            while (min(freqT, freqF) > k) {
                if (answerKey[l] == 'T')
                    freqT--;
                else
                    freqF--;

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
