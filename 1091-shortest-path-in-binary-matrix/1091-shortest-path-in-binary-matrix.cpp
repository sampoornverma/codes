class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 1; // starting cell ka length = 1

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0; k<8; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                    if(dis[nx][ny] > dis[x][y] + 1){
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return (dis[n-1][m-1] == 1e9 ? -1 : dis[n-1][m-1]);
    }
};