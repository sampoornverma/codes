class Solution {
public:
    int maximalSquare(vector<vector<char>>& mati) {
        
        int maxi=0;
        int n=mati.size();
      int m=mati[0].size();
      vector<vector<int>> mat(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mati[i][j]=='1'){
                mat[i][j]=1;
            }
        }
      }
      for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==1){
                mat[i][j]=1+min(mat[i-1][j],min(mat[i-1][j-1],mat[i][j-1]));
                maxi=max(maxi,mat[i][j]);
            }
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                maxi=max(maxi,mat[i][j]);
            
        }
      }
      return maxi*maxi;
    }
};