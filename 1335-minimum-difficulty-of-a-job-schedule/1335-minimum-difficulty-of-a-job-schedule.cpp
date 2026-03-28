class Solution {
public:
     int solve(int i, int days, vector<int>& job, vector<vector<int>>& dp)
    {
        int n = job.size();
        
        if(days == 1)
        {
            int mx = 0;
            for(int j=i;j<n;j++)
                mx = max(mx, job[j]);
            return mx;
        }

        if(dp[i][days] != -1)
            return dp[i][days];

        int maxJob = 0;
        int ans = 1e9;

        for(int k=i; k<=n-days; k++)
        {
            maxJob = max(maxJob, job[k]);

            int next = solve(k+1, days-1, job, dp);

            ans = min(ans, maxJob + next);
        }

        return dp[i][days] = ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        if(d>job.size())return -1;
        if(d==job.size())return accumulate(job.begin(),job.end(),0);
        int n = job.size();


        vector<vector<int>> dp(n, vector<int>(d+1, -1));

        return solve(0, d, job, dp);

    }
};