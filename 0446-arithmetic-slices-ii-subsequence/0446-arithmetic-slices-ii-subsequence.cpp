class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        vector<unordered_map<long long,int>> dp(n);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < i; j++){

                long long diff = (long long)nums[i] - nums[j];

                int cnt = 0;

                if(dp[j].count(diff))
                    cnt = dp[j][diff];

                ans += cnt;

                dp[i][diff] += cnt + 1;
            }
        }

        return ans;
    }
};