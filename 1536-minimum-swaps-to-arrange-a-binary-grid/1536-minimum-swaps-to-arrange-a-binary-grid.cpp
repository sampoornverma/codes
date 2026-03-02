class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // count trailing zeros for each row
        vector<int> tz(n, 0);
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 0) count++;
                else break;
            }
            tz[i] = count;
        }

        int steps = 0;

        // bubble-like process
        for(int i = 0; i < n; i++){
            int need = n - i - 1;
            int j = i;

            // find row with enough trailing zeros
            while(j < n && tz[j] < need) j++;

            if(j == n) return -1;

            // bubble up that row
            while(j > i){
                swap(tz[j], tz[j-1]);
                steps++;
                j--;
            }
        }

        return steps;
    }
};