class Solution {
public:

int maxPoints(vector<vector<int>> &points) {
    int n = points.size(), mx = 0;
    for (int i = 0; i < n; ++i) {
        map<double, int> mp;
        for (int j = i + 1; j < n; ++j) {
            int y = points[i][1] - points[j][1],
                    x = points[i][0] - points[j][0];
            if (x != 0)mp[double(y) / x]++;
            else mp[1e5]++;
        }
        int mxm = 0;
        for (auto item : mp)mxm = max(mxm, item.second);
        mx = max(mx, mxm);
    }
    return mx+1;
}
};