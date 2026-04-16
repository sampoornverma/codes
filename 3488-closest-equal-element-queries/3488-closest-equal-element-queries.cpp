class Solution {
public:
    int findindex(vector<int>& v, int q) {
        int l = 0, h = v.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (v[mid] == q) return mid;
            else if (v[mid] < q) l = mid + 1;
            else h = mid - 1;
        }
        return l; // lower_bound behavior
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int x = findindex(v, q);

            // circular previous
            int prev = v[(x - 1 + v.size()) % v.size()];
            int d1 = abs(q - prev);
            d1 = min(d1, n - d1);

            // circular next
            int next = v[(x + 1) % v.size()];
            int d2 = abs(q - next);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};