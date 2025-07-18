class Solution {
public:
    string makeLargestSpecial(string s) {
    int count = 0, start = 0;
    vector<string> subs;
    for (int i = 0; i < s.size(); ++i) {
        count += (s[i] == '1') ? 1 : -1;
        if (count == 0) {
            string sub = s.substr(start, i - start + 1);
            sub = "1" + makeLargestSpecial(sub.substr(1, sub.size() - 2)) + "0";
            subs.push_back(sub);
            start = i + 1;
        }
    }
    sort(subs.begin(), subs.end(), greater<string>());
    string result;
    for (auto &str : subs) result += str;
    return result;    
    }
};