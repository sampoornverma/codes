class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        if(n==1){return arr[0];}
        if(n==2){return max(arr[0],arr[1]);}
        if(n==3){
            return max(arr[0]+arr[2],arr[1]);
        }
        int f=arr[0];
        int s=arr[1];
        int t=arr[2]+arr[0];
        for(int i=3;i<n;i++){
           int  l=max(s+arr[i],f+arr[i]);
           f=s;
           s=t;
           t=l;
        }
        return max(t,s);
    }

};