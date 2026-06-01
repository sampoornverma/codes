class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=cost.size();
        if(n==1)return cost[0];
        if(n==2)return cost[0]+cost[1];
        int total=0;
        for(int i=0;i<n;i++){
            if((i+1)%3!=0) total=total+cost[i];
        }
        return total;
    }
};