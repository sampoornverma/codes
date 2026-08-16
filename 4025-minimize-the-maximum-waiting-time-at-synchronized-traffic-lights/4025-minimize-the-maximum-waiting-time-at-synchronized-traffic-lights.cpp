class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& a) {
        int mx = *max_element(lights.begin(), lights.end());

        int ans = 0;

        for (int t : a) {
            int r = t % period;

            if (r >= mx) {
                ans = max(ans, period - r);
            }
        }

        return ans;
    }
};