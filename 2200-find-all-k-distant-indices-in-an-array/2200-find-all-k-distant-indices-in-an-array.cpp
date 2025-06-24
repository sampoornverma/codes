class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        vector<int> key_indices;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) key_indices.push_back(i);
        }

        vector<bool> is_k_distant(n, false);
        for (int index : key_indices) {
            int left = max(0, index - k);
            int right = min(n - 1, index + k);
            for (int i = left; i <= right; i++) {
                is_k_distant[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (is_k_distant[i]) result.push_back(i);
        }

        return result;
    }
};