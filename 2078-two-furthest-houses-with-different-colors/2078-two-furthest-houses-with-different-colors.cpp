class Solution {
public:
    int maxDistance(vector<int>& c) {
        int ans=0;
        for(int i=0;i<c.size();i++){
            for(int j=i;j<c.size();j++){
                if(c[i]-c[j]!=0){
                    ans=max(ans,abs(i-j));
                }
            }
        }
        return ans;
    }
};