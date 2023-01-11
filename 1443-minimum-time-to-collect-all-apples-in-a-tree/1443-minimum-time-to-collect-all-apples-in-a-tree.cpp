class Solution {
public:
   #define ll long long
static const ll N = 2e5, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

void dfs(int i, vector<int> edges[], vector<int> &par, vector<bool> &vis) {
    vis[i] = 1;
    for (auto item : edges[i]) {
        if (!vis[item]) {
            par[item] = i;
            dfs(item, edges, par, vis);
        }
    }
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    vector<int> par(n + 5);
    vector<bool> vis(n + 5, 0);
    par[0] = -1;
    vector<int> adj[n+5];
    for (auto i : edges)adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
    dfs(0, adj, par, vis);
    ll cnt = 0;
    map<pair<int, int>, bool> mp;
    for (int i=0;i<n;++i) {
        if (hasApple[i] == 0)continue;

        int x = i;
        while (par[x] != -1) {
            if (mp[{x, par[x]}] == 0)++cnt;
            mp[{x, par[x]}] = 1;
            cout << x << " ";
            x = par[x];
        }
        cout << endl;
    }
    return cnt * 2;
}
 
   
};