class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<long long> small, large;
        long long sumSmall = 0;
        
        // Initial window: indices [1 .. dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            small.insert(nums[i]);
            sumSmall += nums[i];
            if (small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
        }

        long long ans = sumSmall;

        // Slide window
        for (int i = dist + 2; i < nums.size(); i++) {
            int add = nums[i];
            int rem = nums[i - (dist + 1)];

            // Insert new element
            if (!small.empty() && add <= *prev(small.end())) {
                small.insert(add);
                sumSmall += add;
            } else {
                large.insert(add);
            }

            // Remove old element
            if (small.find(rem) != small.end()) {
                small.erase(small.find(rem));
                sumSmall -= rem;
            } else {
                large.erase(large.find(rem));
            }

            // Rebalance
            while (small.size() < k - 1) {
                auto it = large.begin();
                sumSmall += *it;
                small.insert(*it);
                large.erase(it);
            }
            while (small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }

            ans = min(ans, sumSmall);
        }

        return ans + nums[0];
    }
};