class Solution {
public:
    void dfs(vector<vector<int>>& ans, int sr, int sc, int color,int init, vector<int> gr, vector<int> gc){
        ans[sr][sc]=color;
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0;i<4;i++){
            int r=sr+gr[i];
            int c=sc+gc[i];
            if(((c>=0 &&r>=0) && (r<n && c<m))&&(ans[r][c]!=color && ans[r][c]==init)){
                dfs(ans,r,c,color,init,gr,gc);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initalcol=image[sr][sc];
        vector<vector<int>> ans=image;
        vector<int> gr={-1,0,1,0};
        vector<int>  gc={0,1,0,-1};
        dfs(ans,sr,sc,color,initalcol,gr,gc);
        return ans;
    }
};