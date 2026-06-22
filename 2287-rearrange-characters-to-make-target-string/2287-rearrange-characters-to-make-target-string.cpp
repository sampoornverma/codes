class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mp1, mp2;
        for (char c : s)      mp1[c]++;
        for (char c : target) mp2[c]++;

        int res = INT_MAX;
        for (auto& [c, freq] : mp2)
            res = min(res, mp1[c] / freq);

        return res;
    }
};