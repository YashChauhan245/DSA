https://leetcode.com/problems/palindrome-number/description/


//reverse only half string and just compare  with the remaining one 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false; //edge case for negative number

        int rev = 0;
        //iterate till x >rev--->after that just compare
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return (x == rev || x == rev / 10);
    }
};
