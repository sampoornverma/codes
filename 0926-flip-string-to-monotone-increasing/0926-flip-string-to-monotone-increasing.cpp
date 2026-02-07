class Solution {
public:
    int minFlipsMonoIncr(string s) {
    int bCount = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == '1') {
                bCount++;
            } else { // c == 'a'
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;    
    }
};