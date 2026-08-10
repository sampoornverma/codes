class Solution {
public:

    std::vector<std::vector<int>> memo;
    bool winnerSquareGame(int n) {
        memo = std::vector<std::vector<int>>(n + 1, std::vector<int>(2, 0));
        return game(n, true);
    }

    bool game(int n, bool isAlice) {
        int isAliceIdx = isAlice ? 1 : 0;
        if (memo[n][isAliceIdx] != 0) return memo[n][isAliceIdx] == 1;
        int c = 1;
        bool best = !isAlice;
        int i = 1;
        while (c <= n) {
            if (!isAlice) {
                if (!game(n - c, true)) {
                    best = false;
                    break;
                }
            } else {
                if (game(n - c, false)) {
                    best = true;
                    break;
                }
            }
            i++;
            c = i * i;
        }
        memo[n][isAliceIdx] = best ? 1 : 2;
        return best;
    }
};