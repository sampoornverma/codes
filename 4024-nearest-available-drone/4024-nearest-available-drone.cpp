class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int mini=10000;
        int sum=100000;
        for(int i=0;i<n;i++){
            int x=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(x<=drones[i][2] && x<sum){
                sum=x;
                mini=i;
            }
        }
        if(mini==10000)return -1;
        return mini;
    }
};