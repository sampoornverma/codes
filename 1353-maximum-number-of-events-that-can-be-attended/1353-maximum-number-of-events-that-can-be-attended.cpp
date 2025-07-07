#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Sort by end day (greedy: attend event as late as possible)
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Find max end day to create availability calendar
        int maxDay = 0;
        for (auto& e : events)
            maxDay = max(maxDay, e[1]);

        // Calendar of available days (1-indexed)
        vector<bool> used(maxDay + 2, false);
        int count = 0;

        for (auto& e : events) {
            int start = e[0], end = e[1];

            // Try to attend this event on the earliest available day in [start, end]
            for (int d = start; d <= end; ++d) {
                if (!used[d]) {
                    used[d] = true;
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};