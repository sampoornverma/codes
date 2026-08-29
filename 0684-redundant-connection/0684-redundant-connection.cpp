class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void dsu(int n){
        parent.resize(n,-1);

        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionrank(int u,int v){
        u = findparent(u);
        v = findparent(v);

    if (u == v)
        return;

    if (rank[u] > rank[v]) {
        parent[v] = u;
    }

    else if (rank[u] < rank[v]) {
        parent[u] = v;
    }

    else {
        parent[v] = u;
        rank[u]++;
    }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu(n+1);
        int ansx=-1;
        int ansy=-1;
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            if(findparent(x)==findparent(y)){
                ansx=x;
                ansy=y;
            }
            unionrank(x,y);
        }
        return {ansx,ansy};

    }
};