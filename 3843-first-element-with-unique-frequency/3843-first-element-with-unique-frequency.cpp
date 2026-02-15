class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        unordered_map<int,int> mp;
        unordered_map<int,int> mp1;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &m : mp){
            mp1[m.second]++;
        }

        for(int i = 0; i < nums.size(); i++){
            int f = mp[nums[i]];
            if(mp1[f] == 1){
                return nums[i];
            }
        }

        return -1; 
    }
};