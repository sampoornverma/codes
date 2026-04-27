class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},       // 1
        {{-1,0},{1,0}},       // 2
        {{0,-1},{1,0}},       // 3
        {{0,1},{1,0}},        // 4
        {{0,-1},{-1,0}},      // 5
        {{0,1},{-1,0}}        // 6
    };

    bool isValid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n = grid.size(), m = grid[0].size();

        if(i == n-1 && j == m-1) return true;

        vis[i][j] = 1;

        for(auto d : dirs[grid[i][j]]){
            int ni = i + d[0];
            int nj = j + d[1];

            if(isValid(ni,nj,n,m) && !vis[ni][nj]){
                for(auto back : dirs[grid[ni][nj]]){
                    if(ni + back[0] == i && nj + back[1] == j){
                        if(dfs(ni,nj,grid,vis)) return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(0,0,grid,vis);
    }
};