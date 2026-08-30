https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/description/


class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0];
        int sc=source[1];
        int tr=target[0];
        int tc=target[1];

        if(sr==tr && sc==tc){
            return 0;
        }
        //color same?
        if((sr+sc)%2!=(tr+tc)%2){
            return -1;
        }

        //same diagonal?
        if(abs(sr-tr)==abs(sc-tc)){
            return 1;
        }

        //if not same then moves will always be 2
        return 2;
    }
};
