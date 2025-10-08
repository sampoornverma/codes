class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = words[i].size();
        }

        vector<string> s;
        int i = 0;

        while (i < n) {
            string q = "";
            int count = arr[i];
            int j = i + 1;

            // Collect words that fit in the current line
            while (j < n && count + 1 + arr[j] <= maxWidth) {
                count += 1 + arr[j];
                j++;
            }

            int spaces = maxWidth - (count - (j - i - 1)); // total spaces to distribute
            int gaps = j - i - 1;

            // Build line
            if (j == n || gaps == 0) {
                // Last line or single word
                for (int k = i; k < j; k++) {
                    q += words[k];
                    if (k != j - 1) q += " ";
                }
                while (q.size() < maxWidth) q += " ";
            } else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i; k < j; k++) {
                    q += words[k];
                    if (k != j - 1) {
                        q += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            s.push_back(q);
            i = j;
        }

        return s;
    }
};
