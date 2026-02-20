class Solution {
public:
    string makeLargestSpecial(string s) {
    int count = 0, start = 0;
    vector<string> subs;
    for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
        count += 1;
    } else {
        count -= 1;
    }

    // Found a "good" substring
    if (count == 0) {
        int length = i - start + 1;
        string sub = s.substr(start, length);

        // Remove outer '1' and '0', recursively sort the inner part
        string inner = sub.substr(1, length - 2);
        string processed = makeLargestSpecial(inner);

        // Wrap it back with '1' and '0'
        subs.push_back("1" + processed + "0");

        // Move to the next segment
        start = i + 1;
    }
}
    sort(subs.begin(), subs.end(), greater<string>());
    string result;
    for (auto &str : subs) result += str;
    return result;    
    }
};
