class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
       sort(prices.begin(),prices.end(), greater<int>());
       sort(discounts.begin(),discounts.end(), greater<int>());
       int n=min(prices.size(),discounts.size());
       double total=0;
       for(int i=0;i<n;i++){
            total=total+ prices[i] * (100.0 - discounts[i]) / 100.0;
       } 

       for (int i = n; i < prices.size(); i++) {
            total += prices[i];
        }
       return total;
    }
};