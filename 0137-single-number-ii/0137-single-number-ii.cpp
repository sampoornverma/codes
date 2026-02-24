class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32, 0);
        int count=0;
        for (int i = 0; i < nums.size(); i++) {
            string s = bitset<32>(nums[i]).to_string();

            for (int j = 0; j < 32; j++) {
                if (s[j] == '1') {
                    arr[31 - j]++;   
                }
                if (s[j]<0) {
                    count++; 
                }
            }
        }

        int total = 0;

        for (int i = 0; i < 32; i++) {
            if (arr[i] % 3 != 0) {
                total |= (1 << i);  
            }
        }
        if(count%3 !=0)total= total*-1;
        return total;
    }
};