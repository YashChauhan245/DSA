https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/



class Solution {
public:
    int minOperations(string s) {
        int n=s.size();

        //if string already sorted
        if(is_sorted(begin(s),end(s))){
            return 0;
        }

        //if len of s is 2 
        if(n==2){
            return -1;
        }

        //if min at 0 index and max at last index 
        char min=*min_element(begin(s),end(s));
        char max=*max_element(begin(s),end(s));

        if(s[0]==min || s[n-1]==max){
            return 1;
        }

        //if  minimum is at the last position and the maximum is at the first position → 3 else 2
        char minmid=*min_element(begin(s)+1,end(s)-1); //to counter duplicates like 'jgg'
        char maxmid=*max_element(begin(s)+1,end(s)-1);

        if(s[0]>maxmid && s[n-1]<minmid){  // rdca
            return 3;
        }

//if not using midmax and midmin apporach 
    // if(s[0]==max && s[n-1]==min &&// rdca
    //     count(s.begin(), s.end(), min) == 1 &&
    //     count(s.begin(), s.end(), max) == 1) {
    //     return 3;
    // }


        //card
        return 2;

    }
};

