class Solution {
public:
    int sum = 0;
    vector<vector<int>> dp;
    int f(int i, int total, vector<int>& stones) {
        if (i == stones.size()) {
            return abs(sum - 2 * total);
        }
        if (dp[i][total] != -1)
            return dp[i][total];
        int take = f(i + 1, total + stones[i], stones);
        int notTake = f(i + 1, total, stones);
        return dp[i][total] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        sum = 0;
        for (int x : stones)
            sum += x;
        int n = stones.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        return f(0, 0, stones);
    }
};