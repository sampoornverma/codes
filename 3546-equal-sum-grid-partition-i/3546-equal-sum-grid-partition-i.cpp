class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=sum+grid[i][j];
            }

        }
        if(sum%2!=0)return false;
        long long target=sum/2;
        long long sum2=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum2=sum2+grid[j][i];
            }
            if(sum2==target)return true;   
        }
        long long sum1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum1=sum1+grid[i][j];
            }
            if(sum1==target)return true;   
        }
        
    return false;
    }
};