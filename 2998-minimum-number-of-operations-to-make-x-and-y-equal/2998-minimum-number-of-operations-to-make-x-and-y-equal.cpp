class Solution {
public:
    unordered_map<int,int> memo;

    int solve(int x, int y) {
        if (x <= y)
            return y - x;

        if (memo.count(x))
            return memo[x];

        int ans = x - y;  
        int r5 = x % 5;

        ans = min(ans,
                  r5 + 1 + solve(x / 5, y));

        ans = min(ans,
                  (5 - r5) + 1 + solve((x + 5 - r5) / 5, y));
        int r11 = x % 11;

        ans = min(ans,
                  r11 + 1 + solve(x / 11, y));

        ans = min(ans,
                  (11 - r11) + 1 + solve((x + 11 - r11) / 11, y));

        return memo[x] = ans;
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        return solve(x, y);
    }
};