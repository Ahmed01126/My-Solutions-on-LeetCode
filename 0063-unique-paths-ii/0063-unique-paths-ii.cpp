class Solution {
public:
    #define ll long long
const ll N = 25, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()
int n, m;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dp[105][105];
bool check(int x, int y, vector<vector<int>> &arr) {
    return (x < n and x >= 0 and y >= 0 and y < m and arr[x][y] != 1);
}

ll dfs(int x, int y, vector<vector<int>> &arr) {
    if (x == n - 1 && y == m - 1)return arr[x][y] != 1;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y] = 0;
    arr[x][y] = 1;
    for (int i = 0; i < 2; ++i) {
        if (check(x + dx[i], y + dy[i], arr) == 1) {
            dp[x][y] += dfs(x + dx[i], y + dy[i], arr);
        }
    }
    arr[x][y]=0;
    return dp[x][y];

}
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int x = 0, y = 0;
        memset(dp,-1,sizeof(dp));
    if(grid[x][y] == 1)return 0;
    n = grid.size(), m = grid[0].size();
    return dfs(x, y, grid);
}
};