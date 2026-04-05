class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tails;
        vector<int> ans;

        for(int x : obstacles){

            auto it = upper_bound(tails.begin(), tails.end(), x);

            int pos = it - tails.begin();

            if(it == tails.end())
                tails.push_back(x);
            else
                *it = x;

            ans.push_back(pos + 1);
        }

        return ans;
    }
};