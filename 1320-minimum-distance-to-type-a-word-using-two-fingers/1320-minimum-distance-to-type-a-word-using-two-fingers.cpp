class Solution {
public:
    int d(char a, char b){
        if (a == '#' || b == '#') return 0;
        int x = a - 'A';
        int y = b - 'A';
        return abs((x % 6) - (y % 6)) + abs((x / 6) - (y / 6));
    }

    int dp[301][27][27];

    int f(string &w, int a, int b, int i){
        if(i == w.size()) return 0;

        if(dp[i][a][b] != -1) return dp[i][a][b];

        char cur = w[i];

        // convert index to char (26 means '#')
        char ca = (a == 26 ? '#' : a + 'A');
        char cb = (b == 26 ? '#' : b + 'A');

        // move left finger
        int left = d(ca, cur) + f(w, cur - 'A', b, i + 1);

        // move right finger
        int right = d(cb, cur) + f(w, a, cur - 'A', i + 1);

        return dp[i][a][b] = min(left, right);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return f(word, 26, 26, 0); // 26 = no finger placed
    }
};