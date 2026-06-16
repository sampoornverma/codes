class NumArray {
public:
    vector<int> prefix_arr;

    NumArray(vector<int>& nums) {
        prefix_arr.resize(nums.size());
        prefix_arr[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix_arr[i] = prefix_arr[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix_arr[right];
        return (prefix_arr[right] - prefix_arr[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */