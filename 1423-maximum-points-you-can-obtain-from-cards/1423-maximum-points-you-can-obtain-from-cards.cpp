class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        if(k>c.size())return accumulate(c.begin(),c.end(),0);
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            sum=sum+c[i];
            maxi=max(maxi,sum);
        }
        int a=sum;
        int d=c.size()-1;
        int i=k-1;
        while(d!=c.size()-k-1){
            sum=sum-c[i];
            i--;
            sum=sum+c[d];
            d--;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};