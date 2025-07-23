https://leetcode.com/problems/lemonade-change/submissions/1708936335/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int tw=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                tw++;
                if(five>0 && ten>0){
                    five--;
                    ten--;
                }
                else if(five>=3){
                        five=five-3;
                } 
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};
