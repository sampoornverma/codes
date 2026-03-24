class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
 int size = nums.size();
        vector<int> answer(size, 1);

        int prefixs = 1;
        for (int i = 0; i < size; i++) {
            answer[i] = prefixs;
            prefixs *= nums[i];
        }

        int suffixs = 1;
        for (int i = size - 1; i >= 0; i--) {
            answer[i]*= suffixs;
            suffixs *= nums[i];
        }

        return answer;
    }
};