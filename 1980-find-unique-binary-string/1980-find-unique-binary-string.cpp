class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(auto &it : nums) {
            st.insert(stoi(it, nullptr, 2));
        }

        for(int i = 0; i < (1 << n); i++) {
            if(st.count(i) == 0) {
                string s = bitset<16>(i).to_string();
                return s.substr(16 - n);
            }
        }

        return "";
    }
};