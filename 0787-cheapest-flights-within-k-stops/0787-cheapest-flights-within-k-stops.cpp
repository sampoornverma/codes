class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int,pair<int,int>>> pq;
        pq.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int stops = it.first;
            int u = it.second.first;
            int v= it.second.second;
            if(stops>k) continue;
            for(auto t : adj[u]){
            int a= t.first;
            int b=t.second;
            if(v+b<dist[a] && stops<=k){
                dist[a]=v+b;
                pq.push({stops+1,{a,v+b}});
            }
            }
        }

        if(dist[dst]==1e9)return -1;
        else return dist[dst];
    }
};