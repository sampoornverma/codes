#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        if (!node->child[0] && !node->child[1]) return -1; // empty
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                maxXor |= (1 << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> res(queries.size(), -1);
        vector<array<int,3>> offline;
        for (int i = 0; i < queries.size(); i++) {
            offline.push_back({queries[i][1], queries[i][0], i}); // {m, x, idx}
        }
        sort(offline.begin(), offline.end());

        Trie trie;
        int idx = 0, n = nums.size();
        for (auto &q : offline) {
            int m = q[0], x = q[1], qi = q[2];
            while (idx < n && nums[idx] <= m) {
                trie.insert(nums[idx]);
                idx++;
            }
            res[qi] = trie.getMaxXor(x);
        }
        return res;
    }
};