class Solution {
public:

    int findNext(int i, vector<pair<int,pair<int,int>>> &jobs){

        int l = i + 1;
        int r = jobs.size() - 1;
        int ans = jobs.size();

        int endTime = jobs[i].second.first;

        while(l <= r){

            int mid = (l + r) / 2;

            if(jobs[mid].first >= endTime){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    int solve(int i, vector<pair<int,pair<int,int>>> &jobs, vector<int>& dp){

        if(i >= jobs.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int next = findNext(i, jobs);

        int take = jobs[i].second.second + solve(next, jobs, dp);

        int notTake = solve(i+1, jobs, dp);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {

        int n = s.size();

        vector<pair<int,pair<int,int>>> jobs;

        for(int i = 0; i < n; i++){
            jobs.push_back({s[i], {e[i], profit[i]}});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return solve(0, jobs, dp);
    }
};