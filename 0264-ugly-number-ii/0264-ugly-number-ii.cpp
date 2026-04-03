class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;

        pq.push(1);
        seen.insert(1);

        long curr = 1;

        for(int i = 0; i < n; i++)
        {
            curr = pq.top();
            pq.pop();

            long a = curr * 2;
            long b = curr * 3;
            long c = curr * 5;

            if(!seen.count(a)){
                pq.push(a);
                seen.insert(a);
            }

            if(!seen.count(b)){
                pq.push(b);
                seen.insert(b);
            }

            if(!seen.count(c)){
                pq.push(c);
                seen.insert(c);
            }
        }

        return curr;
    }
};