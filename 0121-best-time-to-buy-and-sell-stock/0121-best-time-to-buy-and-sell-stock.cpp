class Solution {
public:
    int maxProfit(vector<int>& arr) {
            int mini=arr[0];
    int n=arr.size();
    int profit=0;
    for(int i=1;i<n;i++){
        profit=max(profit,arr[i]-mini);
        mini=min(mini,arr[i]);
    }
    return profit;
    }
};