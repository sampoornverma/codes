class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;  // Base case: empty subarray

        int count = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;

            // Check if there's a prefix sum that matches prefixSum - k
            if (prefixSumFreq.count(prefixSum - k)) {
                count += prefixSumFreq[prefixSum - k];
            }

            // Store/update current prefix sum frequency
            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};