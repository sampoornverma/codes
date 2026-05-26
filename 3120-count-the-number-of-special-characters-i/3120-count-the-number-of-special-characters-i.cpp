class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> arr(26, 0);

        int n = word.size();

        for (int i = 0; i < n; i++) {

            if (word[i] >= 'A' && word[i] <= 'Z') {
                arr[word[i] - 'A'] = 1;
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (word[i] >= 'a' && word[i] <= 'z'
                && arr[word[i] - 'a'] == 1) {

                count++;

                arr[word[i] - 'a'] = 2;
            }
        }

        return count;
    }
};