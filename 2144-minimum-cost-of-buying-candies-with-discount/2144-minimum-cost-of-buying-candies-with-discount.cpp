class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=cost.size();
        int total=0;
        for(int i=0;i<n;i++){
            if((i+1)%3!=0) total=total+cost[i];
        }
        return total;
    }
};