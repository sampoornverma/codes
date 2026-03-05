class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &count){
        vis[node] = 1;
        count++;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        vector<int> comp;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int count = 0;
                dfs(i, adj, vis, count);
                comp.push_back(count);
            }
        }

        long long ans = 0;
        long long sum = 0;

        for(auto size : comp){
            ans += sum * size;
            sum += size;
        }

        return ans;
    }
};