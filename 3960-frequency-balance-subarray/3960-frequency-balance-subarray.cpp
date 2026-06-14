class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpp,mpp1;
            for(int j=i;j<n;j++){
                int val=nums[j];
                if(mpp[val]>0){
                    int freq=mpp[val];
                    mpp1[freq]--;
                    if(mpp1[freq]==0) mpp1.erase(freq);
                }
                mpp[val]++;
                mpp1[mpp[val]]++;
                if(mpp.size()==1&&mpp1.size()==1) ans=max(ans,j-i+1);
                else if(mpp1.size()==2){
                    auto it=mpp1.begin();
                    int f1=it->first;it++;int f2=it->first;
                    int maxi=max(f1,f2),mini=min(f1,f2);
                    if(maxi==2*mini) ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};