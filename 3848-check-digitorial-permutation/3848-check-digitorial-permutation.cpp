class Solution {
public:
    int p(int n){
        if(n == 0) return 1;
        return n * p(n - 1);
    }

    bool isDigitorialPermutation(int n) {
        int original = n;
        int total = 0;

        while(n > 0){
            int c = n % 10;
            total += p(c);
            n /= 10;
        }

        // check if total is permutation of original
        string a = to_string(original);
        string b = to_string(total);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }
};