class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
     vector<vector<int>> adj(n);
     for(int i=0;i<pre.size();i++){
        adj[pre[i][0]].push_back(pre[i][1]);
     }
     vector<int> indegree(n, 0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0)

                    q.push(it);

            }
        }
        vector<int> s;
        if(topo.size()!= n)return s;
        reverse(topo.begin(),topo.end());
        return topo;
    }
};