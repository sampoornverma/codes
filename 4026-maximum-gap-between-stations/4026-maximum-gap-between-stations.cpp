class Solution {
public:
    int maximumGap(string skill, string station) {
         int n = skill.size(), m = station.size();
        vector<int> left(n), right(n);

        for (int j = 0, p = 0; j < m && p < n; j++)
            if (station[j] == skill[p]) left[p++] = j;

        for (int j = m - 1, p = n - 1; j >= 0 && p >= 0; j--)
            if (station[j] == skill[p]) right[p--] = j;

        int ans = 0;
        for (int i = 0; i + 1 < n; i++)
            ans = max(ans, right[i + 1] - left[i]);

        return ans;
    }
};