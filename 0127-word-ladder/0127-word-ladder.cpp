class Solution {
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {

        // Step 1: store dictionary in set for fast lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If target not present, no transformation possible
        if (st.find(targetWord) == st.end()) return 0;

        // Step 2: BFS queue -> {word, steps}
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        // Remove start word to avoid revisiting
        st.erase(startWord);

        // Step 3: BFS traversal
        while (!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If reached target
            if (word == targetWord) return steps;

            // Try changing every character
            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // If word exists in dictionary
                    if (st.find(word) != st.end()) {

                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};