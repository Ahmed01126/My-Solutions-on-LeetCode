class Solution {
public:
    int maxSubarraySumCircular(vector<int> &v) {
    int n = v.size(), sum = 0, mxSub = -1e9, mnSub = 1e9, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        sum1 += v[i];
        mxSub = max(mxSub, sum1);
        if (sum1 < 0)sum1 = 0;
        sum2 += v[i];
        mnSub = min(mnSub, sum2);
        if (sum2 > 0)sum2 = 0;
    }
    return (sum == mnSub) ? mxSub : max(sum - mnSub, mxSub);
}
};