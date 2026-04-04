class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int n = encodedText.size();
        int cols = n / rows;

        string ans = "";

        for(int start = 0; start < cols; start++) {

            int r = 0;
            int c = start;

            while(r < rows && c < cols) {
                ans += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};