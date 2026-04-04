class Solution {
public:

    unordered_map<string, bool> dp;

    bool solve(string s1, string s2){

        if(s1 == s2) return true;

        string key = s1 + " " + s2;
        if(dp.count(key)) return dp[key];

        int n = s1.size();

        for(int k = 1; k < n; k++){

            // no swap
            if(solve(s1.substr(0,k), s2.substr(0,k)) &&
               solve(s1.substr(k), s2.substr(k)))
                return dp[key] = true;

            // swap
            if(solve(s1.substr(0,k), s2.substr(n-k)) &&
               solve(s1.substr(k), s2.substr(0,n-k)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};