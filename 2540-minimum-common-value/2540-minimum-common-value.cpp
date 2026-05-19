class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int q=0,j=0;
        int n=max(nums1.size(),nums2.size());
        while(j<nums2.size() && q<nums1.size()){
            if(nums1[q]==nums2[j])return nums1[q];
            else if(nums1[q]>nums2[j]) j++;
            else q++;
        }
        
        return -1;
    }
};