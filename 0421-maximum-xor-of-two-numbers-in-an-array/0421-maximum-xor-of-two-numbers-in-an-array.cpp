struct Node {
    Node* link[2]; // 0 or 1
    Node() {
        link[0] = link[1] = nullptr;
    }
    bool contain(int bit) {
        return (link[bit] != nullptr);
    }
    void put(int bit, Node* node) {
        link[bit] = node;
    }
    Node* get(int bit) {
        return link[bit];
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contain(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->contain(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int ans = 0;
        for (int num : nums) {
            ans = max(ans, trie.getMax(num));
        }
        return ans;
    }
};