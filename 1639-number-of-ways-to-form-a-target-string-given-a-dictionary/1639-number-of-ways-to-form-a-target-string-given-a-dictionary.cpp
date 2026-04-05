class Solution {
public:
    const int MOD = 1e9+7;
    long long dp[1001][1001];

    long long f(int i, int j, string &target, vector<vector<int>> &cnt){

        if(i == target.size()) return 1;
        if(j == cnt.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long ways = f(i, j+1, target, cnt); // skip column

        char c = target[i];
        int freq = cnt[j][c-'a'];

        if(freq > 0){
            ways = (ways + (long long)freq * f(i+1, j+1, target, cnt)) % MOD;
        }

        return dp[i][j] = ways;
    }

    int numWays(vector<string>& words, string target) {

        int m = words[0].size();

        vector<vector<int>> cnt(m, vector<int>(26,0));

        for(auto &w: words){
            for(int j=0;j<m;j++){
                cnt[j][w[j]-'a']++;
            }
        }

        memset(dp,-1,sizeof(dp));

        return f(0,0,target,cnt);
    }
};