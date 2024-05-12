class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid[0].length - 2;
        int [][] v = new int[n][n];;
        for (int l = 0; l < n; ++l) {
            for (int k = 0; k < n; ++k) {
                int mx = 0;
                for (int i = l; i < l + 3; ++i) {
                    for (int j = k; j < k + 3; ++j) {
                        if (grid[i][j] >= mx) {
                            mx = grid[i][j];
                        }
                    }
                }
                v[l][k] = mx;
            }
        }
        return v;
    }
}