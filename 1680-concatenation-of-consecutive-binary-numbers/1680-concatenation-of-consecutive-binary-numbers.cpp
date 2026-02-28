class Solution {
public:

    // count binary digits
    int d(int n){
        int i = 0;
        while(n > 0){
            i++;
            n = n / 2;
        }
        return i;
    }

    // binary string
    string s(int n) {
        if (n == 0) return "0";

        string ans = "";
        while (n > 0) {
            ans = char('0' + (n % 2)) + ans;
            n /= 2;
        }
        return ans;
    }

    int concatenatedBinary(int n) {

        // int count = 0;
        // for(int i = 1; i <= n; i++){
        //     count += d(i);
        // }

        long long total = 0;
        int mod = 1e9 + 7;

        for(int i = 1; i <= n; i++){
            string bin = s(i);

            for(int j = 0; j < bin.size(); j++){
                total = (total * 2 + (bin[j] - '0')) % mod;
            }
        }

        return total;
    }
};