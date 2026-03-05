class Solution {
public:
    void sortColors(vector<int>& nums) {
      int low=0;
      int high=nums.size()-1;
      int mid=0;
      while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;mid++;
        }
        else if (nums[mid] == 1) {
                mid++;
            }
            // If current element is 2, swap with high and move only high pointer backward
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
      }


    }
};