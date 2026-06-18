https://leetcode.com/problems/angle-between-hands-of-a-clock/description/?envType=daily-question&envId=2026-06-18

/*
HOURS HAND: 
  360/12=30 ->degree per hour
  30/60 =0.5 ->degree per minute

MINUTE HAND:
  360/60=6 -->6 per minute

AT 3:15:
    Minute hand angle from 12 = 15*6=90
    Hour hand angle from 12 = 3*30+15*0.5=97.5
    ANS = 97.5-90==>7.5
*/


class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double diff = abs(hourAngle - minuteAngle);
        return min(diff,360-diff); 
        //min bcz if Hour hand = 10 , Minute hand = 350 -->diff = abs(10 - 350) = 340 
    }
};
