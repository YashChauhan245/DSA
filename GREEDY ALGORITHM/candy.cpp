https://leetcode.com/problems/candy/

APPROCH -1) USING 2 VECTORS

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>ls(n,1);
        vector<int>rs(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                ls[i]=max(ls[i],ls[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rs[i]=max(rs[i],rs[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(ls[i],rs[i]);
        }
        return ans;
        
    }
};


APPROACH-2) peak and dip algo 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n; //Each person given one candy
        
        int i=1;
        while(i < n){
            
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            
            //Note that we added candies coming from left to Peak and comgin from right to Peak
            //But, we need to consider only max from both of them for the Peak.
            //So, remove the min candy from Peak.
            candy -= min(peak, valley);
        }
        
        return candy;
    }
};


