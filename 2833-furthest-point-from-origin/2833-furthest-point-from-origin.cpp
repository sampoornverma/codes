class Solution {
public:
    int furthestDistanceFromOrigin(string m) {
        int count=0;
        int sum=0;
        for(int i=0;i<m.size();i++){
            if(m[i]=='L')sum--;
            if(m[i]=='R')sum++;
            if(m[i]=='_')count++;
        }
        return count+ abs(sum);
    }
};