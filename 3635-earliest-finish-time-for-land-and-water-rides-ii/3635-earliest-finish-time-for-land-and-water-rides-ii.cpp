class Solution {
public:

    int calc(vector<int>& firstStart,
             vector<int>& firstDuration,
             vector<int>& secondStart,
             vector<int>& secondDuration) {

        int earliestFinish = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            earliestFinish =
                min(earliestFinish,
                    firstStart[i] + firstDuration[i]);
        }

        int answer = INT_MAX;

        for (int i = 0; i < secondStart.size(); i++) {

            int startTime =
                max(earliestFinish, secondStart[i]);

            int finishTime =
                startTime + secondDuration[i];

            answer = min(answer, finishTime);
        }

        return answer;
    }

    int earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        int landFirst =
            calc(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            );

        int waterFirst =
            calc(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            );

        return min(landFirst, waterFirst);
    }
};