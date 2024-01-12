class Solution {
public:
    
#define all(v)        v.begin(), v.end()
int dp[100005];

int goDP(int idx, int n, vector<vector<int>> &jobs, vector<int> &startTime) {
    if (idx == n)return 0;
    if (dp[idx] != 0)return dp[idx];
    int nextStart = lower_bound(all(startTime), jobs[idx][1]) - startTime.begin();
    int left = goDP(idx + 1, n, jobs, startTime);
    int take = jobs[idx][2] + goDP(nextStart, n, jobs, startTime);
    return dp[idx] = max(left, take);
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    vector<vector<int>> jobs;
    for (int i = 0; i < profit.size(); ++i) {
        jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(all(jobs));
    sort(all(startTime));
    return goDP(0, profit.size(), jobs, startTime);
}
};