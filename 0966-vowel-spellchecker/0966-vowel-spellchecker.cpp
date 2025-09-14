class Solution {
public:
    // helper to normalize vowels
    string devowel(string s) {
        for (char &c : s) {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;             // exact matches
        unordered_map<string,string> caseMap;    // lowercase -> first word
        unordered_map<string,string> vowelMap;   // devowel(lowercase) -> first word

        for (string w : wordlist) {
            exact.insert(w);

            string low = w;
            for (auto &c: low) c = tolower(c);

            if (!caseMap.count(low)) caseMap[low] = w;
            if (!vowelMap.count(devowel(low))) vowelMap[devowel(low)] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {                   // 1. exact match
                ans.push_back(q);
                continue;
            }

            string low = q;
            for (auto &c: low) c = tolower(c);

            if (caseMap.count(low)) {               // 2. case-insensitive match
                ans.push_back(caseMap[low]);
                continue;
            }

            string vlow = devowel(low);
            if (vowelMap.count(vlow)) {             // 3. vowel-error match
                ans.push_back(vowelMap[vlow]);
                continue;
            }

            ans.push_back("");                      // 4. no match
        }

        return ans;
    }
};