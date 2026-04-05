class Solution {
public:
    const int mod = 1e9 + 7;

    int f(int i, string &s, int k, vector<int>& arr){

        if(i >= s.size()) return 1;

        if(arr[i] != -1) return arr[i];

        if(s[i] == '0') return arr[i] = 0;

        long long ans = 0;
        long long sum = 0;

        for(int j = i; j < s.size(); j++){

            sum = sum * 10 + (s[j] - '0');

            if(sum > k) break;

            ans = (ans + f(j+1, s, k, arr)) % mod;
        }

        return arr[i] = ans;
    }

    int numberOfArrays(string s, int k) {

        int n = s.size();

        vector<int> arr(n, -1);

        return f(0, s, k, arr);
    }
};