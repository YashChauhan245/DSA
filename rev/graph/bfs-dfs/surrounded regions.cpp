https://leetcode.com/problems/surrounded-regions/description/

//dfs 
class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&visited){
        int m = board.size();
        int n = board[0].size();
        //step-4) mrk visited
        visited[i][j] = 1;

        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
//  First find new index for all 4 directions, and if it is not out of bounds and if it is 'O', then call DFS for that neighbor
        for(int k = 0; k < directions.size(); k++) {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];
            //safe
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && !visited[ni][nj]) {
                dfs(ni, nj, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        //step-1) make visited matrix
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        //step-2)iterate in bounday row and column
        for(int j=0;j<n;j++){
            //top row 
            if(board[0][j]=='O' && !visited[0][j]){
                //step-3) call dfs
                dfs(0,j,board,visited);
            }
            //last row
            if(board[m-1][j]=='O'&&!visited[m-1][j]){
                dfs(m-1,j,board,visited);
            }
        }

        for(int i=0;i<m;i++){
            //1st coln
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i,0,board,visited);
            }
            //last coln
            if(board[i][n-1]=='O' && !visited[i][n-1]){
                dfs(i,n-1,board,visited);
            }
        }

        //step-5)iterate in gird and convert all the 0 to X if not visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};


//bfs 

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto &d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O' && !visited[nx][ny]) { 
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // top & bottom
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !visited[0][j])
                bfs(0, j, board, visited);

            if(board[m-1][j] == 'O' && !visited[m-1][j])
                bfs(m-1, j, board, visited);
        }

        // left & right
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                bfs(i, 0, board, visited);

            if(board[i][n-1] == 'O' && !visited[i][n-1])
                bfs(i, n-1, board, visited);
        }

        // flip
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
