class Solution {
public:
    long long dp[105][105];
    int minPath(vector<vector<int>>& v,int n,int i,int j){
        if(j == n || j < 0)return 1e9;
        if(i==n)return 0;
        if(dp[i][j]!=1e9)return dp[i][j];
        int diagonalLeft = v[i][j] + minPath(v,n,i+1,j-1);
        int diagonalRight = v[i][j] + minPath(v,n,i+1,j+1);
        int down = v[i][j] + minPath(v,n,i+1,j);
        return dp[i][j] = min({diagonalLeft,diagonalRight,down});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=0;i<105;++i){
            for(int j=0;j<105;++j) dp[i][j] = 1e9;
        }
        int n = matrix.size();
        int mn = 1e9;
        for(int j=0;j<n;++j)mn=min(mn,minPath(matrix,n,0,j));
        return mn;
    }
};