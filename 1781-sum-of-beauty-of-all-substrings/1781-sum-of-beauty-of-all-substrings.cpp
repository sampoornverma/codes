class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        long long ans = 0; // use long long to avoid intermediate overflow

        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};
            int maxc = 0;
            for (int j = i; j < n; ++j) {
                int id = s[j] - 'a';
                freq[id]++;
                if (freq[id] > maxc) maxc = freq[id];

                int minc = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0 && freq[k] < minc) minc = freq[k];
                }
                if (minc != INT_MAX) ans += (maxc - minc);
            }
        }

        return (int)ans;
    }
};