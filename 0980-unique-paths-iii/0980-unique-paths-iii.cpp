class Solution {
public:
    #define ll long long
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    bool check(int x, int y, vector<vector<int>> &arr) {
        return (x < n and x >= 0 and y >= 0 and y < m and arr[x][y] != -1);
    }

    int dfs(int x, int y, int zeros, vector<vector<int>> &arr) {
        if (arr[x][y] == 2)return zeros == -1;
        int totalPaths = 0;
        arr[x][y] = -1;
        --zeros;
        for (int i = 0; i < 4; ++i) {
            if (check(x + dx[i], y + dy[i], arr) == 1) {
                totalPaths += dfs(x + dx[i], y + dy[i], zeros, arr);
            }
        }
        ++zeros;
        arr[x][y]=0;
        return totalPaths;

    }

    int uniquePathsIII(vector<vector<int>> &grid) {
        int zeros = 0;
        int x = -1, y = -1;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0)++zeros;
                else if (grid[i][j] == 1)x = i, y = j;
            }
        }
        return dfs(x, y, zeros, grid);
    }
};