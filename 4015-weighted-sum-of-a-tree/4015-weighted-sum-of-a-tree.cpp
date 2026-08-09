class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1)continue;
            else{
                adj[parent[i]].push_back(i);
            }
        }
        int maxi=0;
        queue<pair<int,int>> q;
        q.push({1,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int a=it.first;
            int b=it.second;
            maxi=max(maxi,a);
            for(int x:adj[b]){
                q.push({a+1,x});
            }
        }
        long long ans=0;
        queue<pair<int,int>> q1;
        q1.push({1,0});
        while(!q1.empty()){
            auto it=q1.front();
            q1.pop();
            int a=it.first;
            int b=it.second;
            ans=ans+1LL*nums[b]*(maxi-a+1);
            for(int x:adj[b]){
                q1.push({a+1,x});
            }
        }
        return ans;

    }
};