class Solution {
public:
    int dp[501][501][2];

    int f(vector<int>& p,int i,int j,int turn){
        if(i > j) return 0;

        if(dp[i][j][turn] != -1) return dp[i][j][turn];

        if(turn == 0){ // Alice (maximize)
            int left = p[i] + f(p, i+1, j, 1);
            int right = p[j] + f(p, i, j-1, 1);
            return dp[i][j][turn] = max(left, right);
        }
        else{ // Bob (minimize Alice's score)
            int left = f(p, i+1, j, 0);
            int right = f(p, i, j-1, 0);
            return dp[i][j][turn] = max(left, right);
        }
    }

    bool stoneGame(vector<int>& p) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(p.begin(), p.end(), 0);
        int alice = f(p, 0, p.size()-1, 0);
        return alice > total - alice;
    }
};