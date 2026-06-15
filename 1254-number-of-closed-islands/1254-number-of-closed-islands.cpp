class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>>& grid){
        vis[i][j]=true;
        vector<int> gc={-1,0,1,0};
        vector<int> gr={0,-1,0,1};
        for(int k=0;k<4;k++){
            int l=gc[k]+i;
            int g=gr[k]+j;
            if(l>=0 && l<grid.size() && g>=0 && g<grid[0].size() ){
                if(vis[l][g]==false && grid[l][g]==0){
                    dfs(l,g,vis,grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)dfs(i,0,vis,grid);
            if(grid[i][m-1]==0)dfs(i,m-1,vis,grid);
        }
        for(int j=0;j<m;j++){
              if(grid[0][j]==0)dfs(0,j,vis,grid);
            if(grid[n-1][j]==0)dfs(n-1,j,vis,grid);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==0){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;


    }
};