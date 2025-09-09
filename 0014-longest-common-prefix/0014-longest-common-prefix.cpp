struct Node {
    Node* link[26];
    int count = 0;   // number of words passing through this node
    bool end = false;

    Node() {
        for (int i = 0; i < 26; i++) link[i] = nullptr;
    }

    bool contain(char c) {
        return (link[c - 'a'] != nullptr);
    }

    Node* get(char c) {
        return link[c - 'a'];
    }

    void put(char c, Node* node) {
        link[c - 'a'] = node;
    }

    void inc() {
        count++;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string &w) {
        Node* node = root;
        for (char c : w) {
            if (!node->contain(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
            node->inc();   
        }
        node->end = true;
    }

    string getLCP(int totalWords) {
        string prefix = "";
        Node* node = root;
        while (true) {
            int nextChar = -1;
            for (int i = 0; i < 26; i++) {
                if (node->link[i] != nullptr && node->link[i]->count == totalWords) {
                    nextChar = i;
                    node = node->link[i];
                    prefix.push_back('a' + i);
                    break;
                }
            }
            if (nextChar == -1) break;
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        Trie trie;
        for (auto &word : s) {
            trie.insert(word);
        }
        return trie.getLCP(s.size());
    }
};