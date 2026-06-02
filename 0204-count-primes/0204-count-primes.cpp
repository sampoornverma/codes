class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true);
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j=j+i)isprime[j]=0;
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                count++;
            }
        }
        return count;

    }
};