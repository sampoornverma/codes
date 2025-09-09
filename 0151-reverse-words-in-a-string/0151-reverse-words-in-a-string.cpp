class Solution {
public:
    string reverseWords(string s) {
        string final = "";
        string a = "";  
        for (char c : s) {
            if (c == ' ') {   // ✅ use single quotes for char
                if (!a.empty()) {   // ✅ word complete
                    if (!final.empty()) final = " " + final;
                    final = a + final;
                    a = "";
                }
            } else {
                a = a + c;
            }
        }
        // ✅ add the last word after loop
        if (!a.empty()) {
            if (!final.empty()) final = " " + final;
            final = a + final;
        }
        return final;
    }
};