class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : arr) {
        freq[num]++;
    }

    int res = -1;
    for (auto& [num, count] : freq) {
        if (num == count) {
            res = max(res, num); // Find the largest lucky number
        }
    }

    return res;
    }
};