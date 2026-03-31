class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int d=g.size();
        int a=s.size();
        int i=0,x=0;
        int count=0;
        while( i<d && x<a ){
            if(s[x] >= g[i]){
                count++;
                x++;
                i++;
            }else{x++;}
            
        }
        return count;
    }
};