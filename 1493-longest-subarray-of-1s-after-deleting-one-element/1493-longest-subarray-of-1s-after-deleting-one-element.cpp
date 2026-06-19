class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int i=0;
        int j=0;
        int maxi=0;
        int zero=0;
        while (j < n) {

            if (nums[j] == 0) zero++;

            while (zero > 1) {
                if (nums[i] == 0) zero--;
                i++;

            }

            maxi = max(maxi, j - i); 

            j++;

        }
        return maxi;
    }
};