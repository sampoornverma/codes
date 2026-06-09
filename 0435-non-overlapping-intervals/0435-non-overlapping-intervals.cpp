class Solution {
public:
    static bool comp(vector<int> &v1 , vector<int> &v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , comp);
        int n = intervals.size();
        int cnt = 1;
        int lastEnd = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] >= lastEnd){
                cnt++;
                lastEnd = intervals[i][1];
            }
        }

        return n - cnt;
    }
};