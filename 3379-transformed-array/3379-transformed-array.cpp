class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int idx = (i + nums[i]) % n;
            if (idx < 0) idx += n;   // handle negative modulo
            res[i] = nums[idx];
        }

        return res;
    }
};