class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for(int i = 0; i < nums1.size(); i++){
            // find first element < nums1[i] in decreasing array
            auto it = upper_bound(nums2.begin(), nums2.end(), nums1[i], greater<int>());
            
            // step back to get last valid position
            if(it != nums2.begin()) {
                it--;
                int j = it - nums2.begin();
                
                if(j >= i) {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans;
    }
};