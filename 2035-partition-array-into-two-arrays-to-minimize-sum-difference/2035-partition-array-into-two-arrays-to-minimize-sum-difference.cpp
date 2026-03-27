class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<vector<int>> L(half + 1), R(half + 1);

        for(int mask = 0; mask < (1 << half); mask++){
            int bits = __builtin_popcount(mask);
            int sum = 0;

            for(int i = 0; i < half; i++){
                if(mask & (1 << i))
                    sum += left[i];
            }

            L[bits].push_back(sum);
        }

        for(int mask = 0; mask < (1 << half); mask++){
            int bits = __builtin_popcount(mask);
            int sum = 0;

            for(int i = 0; i < half; i++){
                if(mask & (1 << i))
                    sum += right[i];
            }

            R[bits].push_back(sum);
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for(int k = 0; k <= half; k++){
            auto &a = L[k];
            auto &b = R[half - k];

            sort(b.begin(), b.end());

            for(int x : a){

                int target = total/2 - x;

                auto it = lower_bound(b.begin(), b.end(), target);

                if(it != b.end())
                    ans = min(ans, abs(total - 2*(x + *it)));

                if(it != b.begin()){
                    --it;
                    ans = min(ans, abs(total - 2*(x + *it)));
                }
            }
        }

        return ans;
    }
};