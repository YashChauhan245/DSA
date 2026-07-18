https://leetcode.com/contest/biweekly-contest-187/problems/maximum-value-of-an-alternating-sequence/description/

class Solution {
public:
    long long solve(long long i, long long  s, long long  m,bool firstinc){
        if(i<=0){
            return s;
        }
        
        long long numinc,numdec;
        if(firstinc){
            numinc=(i+1)/2;
            numdec=i/2;
        }
        else{
            numinc=i/2;
            numdec=(i+1)/2;
        }
        return s+numinc*m-numdec;
    }

    long long best(int n,int s,int m,bool firstinc){
        long long mx=s;
        for(long long i :{(long long )n-1,(long long)n-2}){
            if(i<0){
                continue;
            }
            mx=max(mx,solve(i,s,m,firstinc));
        } 
        return mx;
    }
    
    long long maximumValue(int n, int s, int m) {
        return max(best(n,s,m,true),best(n,s,m,false));
    }
};©leetcode
