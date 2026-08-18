class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int, int> mp;
        if(n==k) return *max_element(nums.begin(), nums.end());
        else{
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            if(k==1){
                for(auto it: mp){
                    if(it.second==1){
                        ans=max(ans, it.first);
                    }
                }
                return ans;
            }

            int st=mp[nums[0]];
            int ls=mp[nums[n-1]];
            if(st==1 && ls==1) return max(nums[0], nums[n-1]);
            else if(st==1) return nums[0];
            else if(ls==1) return nums[n-1];
        }
        return -1;
    }
};