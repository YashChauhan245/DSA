https://leetcode.com/problems/even-number-of-knight-moves/description/


class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx[]={1,1,-1,-1,2,2,-2,-2};
        int dy[]={2,-2,2,-2,1,-1,1,-1};

        vector<vector<int>>dist(8,vector<int>(8,-1));
        queue<pair<int,int>>q;

        dist[start[0]][start[1]]=0;
        q.push({start[0],start[1]});

        while(!q.empty()){
            auto[x,y]=q.front(); 
            q.pop();
            if(x==target[0] && y==target[1]){
                break;
            }

            for(int i=0;i<8;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<8 && ny>=0 && ny<8 && dist[nx][ny]==-1){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return dist[target[0]][target[1]]%2==0;
    }
};
