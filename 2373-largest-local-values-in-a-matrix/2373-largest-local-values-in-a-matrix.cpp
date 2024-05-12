class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int n = grid[0].size() - 2;
        vector<vector<int>> v(n, vector<int>(n));
        for (int l = 0; l < n; ++l) {
            for (int k = 0; k < n; ++k) {
                int mx = 0;
                for (int i = l; i < l+3; ++i) {
                    for (int j = k; j < k+3; ++j) {
                        mx = max(mx, grid[i][j]);
                    }
                }
                v[l][k] = mx;
            }
        }
        return v;
    }
};