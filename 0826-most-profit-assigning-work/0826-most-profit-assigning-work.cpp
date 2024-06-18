class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    vector<pair<int, int>> v;
    int n = profit.size();
    for (int i = 0; i < n; ++i) {
        v.push_back({difficulty[i], profit[i]});
    }
    sort(v.begin(), v.end());
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        difficulty[i] = v[i].first;
        mx = max(mx, v[i].second);
        profit[i] = mx;
    }
    int sum = 0, m = worker.size();
    for (int i = 0; i < m; ++i) {
        int idx = upper_bound(difficulty.begin(), difficulty.end(), worker[i]) - difficulty.begin();
        if (idx >= m) {
            sum += profit.back();
        } else if (idx > 0) {
            sum += profit[idx - 1];
        }
    }
    return sum;
}
};