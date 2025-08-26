class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        // Min-heap: {cost, {node, stops}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!pq.empty()){
            auto [cost, state] = pq.top();
            pq.pop();
            int u = state.first;
            int stops = state.second;

            if(u == dst) return cost; // reached destination

            if(stops > k) continue; // exceeded max stops

            for(auto [v, price] : adj[u]){
                if(cost + price < dist[v] || stops < k){
                    dist[v] = cost + price;
                    pq.push({cost + price, {v, stops+1}});
                }
            }
        }

        return -1;
    }
};