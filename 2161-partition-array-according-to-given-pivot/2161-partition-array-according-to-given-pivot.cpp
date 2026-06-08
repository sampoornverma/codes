class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        if(nums.size()==1)return nums;
        int count=0;

        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)count++;
            if(nums[i]==pivot)count1++;
        }
        int l=0;
        int j=count;
        int k=count1+count;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){ans[l]=nums[i];l++;}
            if(nums[i]==pivot){ans[j]=nums[i];j++;}
            if(nums[i]>pivot){ans[k]=nums[i];k++;}
        }
        return ans;

    
    }
};