class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
     for(int i=0;i<n.size();i++){
        if(maxi<n[i]-'0'){
            maxi=max(maxi,n[i]-'0');
        }
     }
     return maxi;   
    }
};