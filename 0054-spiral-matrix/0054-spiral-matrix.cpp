class Solution {
public:
    
#define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 5e4 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()


vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    if(n==1)return matrix[0];
    vector<int> ans;
    int sn = 0, sm = 0;
    vector<vector<int>> vis(n + 2, vector<int>(m + 2, -200));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            vis[i][j] = matrix[i-1][j-1];
        }
    }
    bool l = 0, r = 1, u = 0, d = 0;
    for (int i = 1; i < n + 1;) {
        for (int j = 1; j < m + 1;) {
            
            ans.push_back(vis[i][j]);
            if (vis[i + 1][j] == -200 &&
                vis[i - 1][j] == -200 &&
                vis[i][j - 1] == -200 &&
                vis[i][j + 1] == -200
                    )
                return ans;
            // cout << "i = "<<i <<" j = "<< j ;
            vis[i][j] = -200;
            if (r == 1) {
                if (vis[i][j + 1] == -200)r = 0, d = 1, ++i;
                else ++j;
            } else if (d == 1) {
                if (vis[i + 1][j] == -200)d = 0, l = 1, --j;
                else ++i;
            } else if (l == 1) {
                if (vis[i][j - 1] == -200)l = 0, u = 1, --i;
                else --j;
            } else if (u == 1) {
                if (vis[i - 1][j] == -200)u = 0, r = 1, ++j;
                else --i;
            }
            
            
        }

    }
    return ans;
}
};