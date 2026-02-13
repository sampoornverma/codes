class Solution {
public:
    vector<int> seg;
    int n;

    void build(vector<int>& h, int i, int l, int r) {
        if (l == r) {
            seg[i] = l;
            return;
        }

        int mid = (l + r) / 2;

        build(h, 2*i+1, l, mid);
        build(h, 2*i+2, mid+1, r);

        int leftIdx = seg[2*i+1];
        int rightIdx = seg[2*i+2];

        seg[i] = (h[leftIdx] >= h[rightIdx]) ? leftIdx : rightIdx;
    }

    int findFirst(vector<int>& h, int i, int l, int r,
                  int ql, int qr, int val) {

        if (r < ql || l > qr) return -1;
        if (h[seg[i]] <= val) return -1;

        if (l == r) return l;

        int mid = (l + r) / 2;

        int leftAns = findFirst(h, 2*i+1, l, mid, ql, qr, val);
        if (leftAns != -1) return leftAns;

        return findFirst(h, 2*i+2, mid+1, r, ql, qr, val);
    }

    vector<int> leftmostBuildingQueries(vector<int>& h,
                                        vector<vector<int>>& queries) {

        n = h.size();
        seg.resize(4*n);
        build(h, 0, 0, n-1);

        vector<int> ans;

        for (auto &q : queries) {
            int a = q[0], b = q[1];

            if (a == b) {
                ans.push_back(b);
                continue;
            }

            int l = min(a, b);
            int r = max(a, b);

            if (h[l] < h[r]) {
                ans.push_back(r);
                continue;
            }

            int res = findFirst(h, 0, 0, n-1, r+1, n-1, h[l]);
            ans.push_back(res);
        }

        return ans;
    }
};