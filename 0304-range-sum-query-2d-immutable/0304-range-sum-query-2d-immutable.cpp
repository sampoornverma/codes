class NumMatrix {
public:
    vector<vector<int>> ps; 
    NumMatrix(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n == 0) return;
        int m = (int)matrix[0].size();
        ps.assign(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ps[i][j+1] = ps[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; ++r) {
            sum += ps[r][col2+1] - ps[r][col1];
        }
        return sum;
    }
};