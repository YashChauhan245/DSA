https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31

class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        long long n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());

        for(long long i=0;i<n;i++){
            if(asteroids[i]<=mass){
                mass+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
