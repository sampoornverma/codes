class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long total=mass;
        if(total<a[0])return false;
        for(int i=0;i<a.size()-1;i++){
            total=total+a[i];
            if(total<a[i+1])return false;
        }
        return true;
    }
};