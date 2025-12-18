class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        vector<long long> P(n + 1, 0), SP(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            P[i + 1] = P[i] + prices[i];
            SP[i + 1] = SP[i] + 1LL * strategy[i] * prices[i];
        }
        
        long long originalProfit = SP[n];
        long long bestGain = 0;
        int half = k / 2;
        
        for (int l = 0; l + k <= n; l++) {
            int r = l + k;
            
            long long oldProfit = SP[r] - SP[l];
            
            long long newProfit = P[r] - P[l + half];
            
            bestGain = max(bestGain, newProfit - oldProfit);
        }
        
        return originalProfit + bestGain;
    }
};