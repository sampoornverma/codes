class Solution {
public:
    void f(vector<int>& c, int t,vector<int> &arr,int i,vector<vector<int>>& ans){
        if(i>=c.size() && t>0)return;
        if(t==0){
            ans.push_back(arr);
            return;
        }
        if(t<0) return ;
        arr.push_back(c[i]);
        f(c,t-c[i],arr,i,ans);
        arr.pop_back();


        f(c,t,arr,i+1,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(c,t,arr,0,ans);
        return ans;
    }
};