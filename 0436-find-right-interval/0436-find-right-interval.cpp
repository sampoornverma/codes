class Solution {
public:
    int g(map<int,int>& mp, int a) {
        auto it = mp.lower_bound(a); 
        if (it == mp.end()) return -1;
        return it->second;  
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp; 
        int n = intervals.size();
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = g(mp, intervals[i][1]);
        }

        return arr;
    }
};