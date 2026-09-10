class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int maxi=-1;
        vector<bool>vis(n,false);
        for(int i=0;i<edges.size();i++)
         {  
            if(vis[i]==true) continue;
            unordered_map<int,int>mpp;
            maxi=max(maxi,dfs(i,vis,mpp,edges,0)) ;
         }
         return maxi;
    }
    int dfs(int node,vector<bool>& visited,unordered_map<int,int>& mpp,vector<int>&edges,int curr)
     {
        if(visited[node]==true)
         {
            if(mpp.find(node)==mpp.end()) return -1;
            return curr-mpp[node];
         }
        else{
            mpp[node]=curr;
            curr++;
            visited[node]=true;
            if(edges[node]==-1) return -1;
            return dfs(edges[node],visited,mpp,edges,curr);
        }
       
     }
    
};