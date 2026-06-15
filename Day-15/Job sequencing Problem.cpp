class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {

        sort(Jobs.begin(), Jobs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] > b[2]; // sort by profit descending
             });

        int maxDeadline = 0;

        for(auto &job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        for(auto &job : Jobs) {

            int jobId = job[0];
            int deadline = job[1];
            int profit = job[2];

            for(int j = deadline; j > 0; j--) {

                if(slot[j] == -1) {
                    slot[j] = jobId;

                    countJobs++;
                    totalProfit += profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};
