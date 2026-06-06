class Solution {
public:
    long long minEnergy(int ng, int bri, vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n=in.size();
        int prev=in[0][0];
        int start=in[0][0];
        long long total=0;
        if(n==1){
            long long f=0;
            if(bri%3==0)f=bri/3;
            else f=(bri/3)+1;
            long long j=((in[0][1]-in[0][0]+1)*f);
            return j ;
        }
        bool x=false;
        for(int i=0;i<n;i++){
            if(in[i][0]<=prev){
                prev=max(prev,in[i][1]);
                x=true;
                }
            else{
                total=total+prev-start+1;
                start=in[i][0];
                prev=in[i][1];
                if(i==n-1)total=total+prev-start+1;
                x=false;
            }
        }
        if(x)total=total+prev-start+1;
        int f=0;
            if(bri%3==0)f=bri/3;
            else f=(bri/3)+1;
            return (total*f);


    }
};