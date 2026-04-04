class Solution {
public:

    int nextIndex(int day, vector<int>& days){
        for(int i = 0; i < days.size(); i++){
            if(days[i] >= day) return i;
        }
        return days.size();
    }

    int f(int i, vector<int>& days, vector<int>& costs, vector<int>& dp){

        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int a = costs[0] + f(nextIndex(days[i] + 1, days), days, costs, dp);
        int b = costs[1] + f(nextIndex(days[i] + 7, days), days, costs, dp);
        int c = costs[2] + f(nextIndex(days[i] + 30, days), days, costs, dp);

        return dp[i] = min(a, min(b, c));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp(n, -1);

        return f(0, days, costs, dp);
    }
};