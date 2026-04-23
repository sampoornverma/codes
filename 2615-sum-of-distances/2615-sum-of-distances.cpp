class Solution {
public:
    
    int findbybinarysearch(int idx, vector<int>& nums, unordered_map<int, vector<int>>& mp) {
        auto &v = mp[nums[idx]];
        int l = 0, r = v.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] == idx) return mid;
            else if(v[mid] < idx) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dis(n, 0);

        unordered_map<int, vector<int>> mp;
        unordered_map<int, vector<long long>> pref;

        // Step 1: store indices
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // Step 2: build prefix sum for each value
        for(auto &it : mp){
            auto &v = it.second;
            int m = v.size();
            vector<long long> p(m, 0);
            p[0] = v[0];
            for(int i = 1; i < m; i++){
                p[i] = p[i-1] + v[i];
            }
            pref[it.first] = p;
        }

        // Step 3: compute answer
        for(int i = 0; i < n; i++){
            int val = nums[i];
            auto &v = mp[val];
            auto &p = pref[val];

            int pos = findbybinarysearch(i, nums, mp);

            // left side
            long long left = (long long)i * pos - (pos > 0 ? p[pos-1] : 0);

            // right side
            long long right = (p.back() - p[pos]) - (long long)i * (v.size() - pos - 1);

            dis[i] = left + right;
        }

        return dis;
    }
};