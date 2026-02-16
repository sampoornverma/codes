class Solution {
public:
    void dfs(vector<int> &a,vector<vector<int>>& graph,int start,int end,
    vector<vector<int>> &arr){
        a.push_back(start);
        if(start==end){
            
            arr.push_back(a);
            a.pop_back();
            return ;
            }
        for(int i=0;i<graph[start].size();i++){
            dfs(a,graph,graph[start][i],end,arr);
        }
        a.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<vector<int>> arr;
        vector<int> a;
        dfs(a,graph,0,n-1,arr);
   
    return arr;    
    }
};