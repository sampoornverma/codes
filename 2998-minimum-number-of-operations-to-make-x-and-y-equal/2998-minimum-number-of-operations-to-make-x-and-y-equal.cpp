class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {

        queue<pair<int,int>> q;
        unordered_set<int> vis;

        q.push({x,0});
        vis.insert(x);

        while(!q.empty()) {
            auto [cur,steps] = q.front();
            q.pop();

            if(cur == y) return steps;

            vector<int> nxt;

            nxt.push_back(cur - 1);
            nxt.push_back(cur + 1);

            if(cur % 5 == 0) nxt.push_back(cur / 5);
            if(cur % 11 == 0) nxt.push_back(cur / 11);

            for(int num : nxt) {

                if(num < 0 || num > 10000) continue;

                if(!vis.count(num)) {
                    vis.insert(num);
                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};