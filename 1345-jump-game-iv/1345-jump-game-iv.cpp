class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            adj[arr[i]].push_back(i);
        }

        //        node, distance
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()){
            auto [u, d] = q.front();
            q.pop();

            if(u == n - 1) return d;

            // go to the left node
            if(u - 1 >= 0 && !vis[u - 1]){
                q.push({u - 1, d + 1});
                vis[u - 1] = 1;
            }

            // go to the right node
            if(u + 1 < n && !vis[u + 1]){
                q.push({u + 1, d + 1});
                vis[u + 1] = 1;
            }

            // go to node v that arr[u] == a[v]
            for(int v : adj[arr[u]]){
                if(!vis[v]){
                    q.push({v, d + 1});
                    vis[v] = 1;
                }
            }

            // to reduce time complexity and don't loop over the same number again
            adj[arr[u]].clear();
        }

        return -1;
    }
};