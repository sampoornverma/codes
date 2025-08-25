class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;

        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;

        pq.push({0, {0,0}});

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};

        while(!pq.empty()){
            auto [effort, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if(x == n-1 && y == m-1) return effort;

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newEffort = max(effort, abs(grid[x][y] - grid[nx][ny]));
                    if(dis[nx][ny] > newEffort){
                        dis[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0; // should never reach here
    }
};