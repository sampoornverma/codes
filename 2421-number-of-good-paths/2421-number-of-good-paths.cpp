class Solution {
public:
    vector<int> parent, rank1;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(rank1[a] < rank1[b]) swap(a, b);

        parent[b] = a;
        if(rank1[a] == rank1[b]) rank1[a]++;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        parent.resize(n);
        rank1.resize(n, 0);

        for(int i = 0; i < n; i++) parent[i] = i;

        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[vals[i]].push_back(i);
        }

        int result = n; // single nodes

        vector<bool> active(n, false);

        for(auto &it : mp){
            auto &nodes = it.second;

            // activate nodes
            for(auto u : nodes){
                active[u] = true;

                for(auto v : adj[u]){
                    if(active[v]){
                        unite(u, v);
                    }
                }
            }

            // count nodes in each component
            unordered_map<int, int> count;

            for(auto u : nodes){
                int root = find(u);
                count[root]++;
            }

            for(auto &p : count){
                int k = p.second;
                result += (k * (k - 1)) / 2;
            }
        }

        return result;
    }
};