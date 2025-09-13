class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowels(26, 0), consonants(26, 0);
        
        // Count frequency separately for vowels & consonants
        for (char c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vowels[c - 'a']++;
            else
                consonants[c - 'a']++;
        }

        // Sort descending
        sort(vowels.begin(), vowels.end(), greater<int>());
        sort(consonants.begin(), consonants.end(), greater<int>());

        int sum = 0;
int maxV=0;
        if(vowels.size()>0) maxV = vowels[0];
        for (int f : vowels) {
            
            if (f == maxV) sum += f;
             break;
        }
        int maxC=0;
        if(consonants.size()>0) maxC = consonants[0];
        for (int f : consonants) {
            
            if (f == maxC) sum += f;
             break;
        }

        return sum;
    }
};