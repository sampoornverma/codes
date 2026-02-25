class Solution {
public:
   static bool comp(int a, int b) {
    int pa = __builtin_popcount(a);
    int pb = __builtin_popcount(b);

    if (pa == pb)
        return a < b;   // tie-breaker
    return pa < pb;
}
    vector<int> sortByBits(vector<int>& v) {
    sort(v.begin(), v.end(), comp);

    return v;

    }
};