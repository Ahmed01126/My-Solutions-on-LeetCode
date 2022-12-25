class Solution {
public:
    #define ll long long
    const ll N = 1e6 + 50, NN = 105, mod = 1e9 + 7;
    ll dp[1005][4];
    // t = 0 --> filled
    ll goDp(ll i, ll t1, ll t2, ll n) {
        if (i == n)return 1;
        // 00 --> 0 and 10 --> 1 and 01 --> 2 and 11 --> 3
        ll state = (t1 ? 1 : 0) + (t2 ? 2 : 0);
        if (dp[i][state] != -1)return dp[i][state];
        ll cnt = 0;
        ll t3 = i + 1 < n, t4 = i + 1 < n;

        if (t1 and t2 and t3)cnt += goDp(i + 1, 0, 1, n);
        if (t1 and t2 and t4)cnt += goDp(i + 1, 1, 0, n);

        if (t1 and !t2 and t3 and t4)cnt += goDp(i + 2, 1, 1, n);
        if (!t1 and t2 and t3 and t4)cnt += goDp(i + 2, 1, 1, n);

        if (t1 and t2)cnt += goDp(i + 1, 1, 1, n);
        if (t1 and t2 and t3 and t4)cnt += goDp(i + 2, 1, 1, n);

        if (t1 and !t2 and t3)cnt += goDp(i + 1, 0, 1, n);
        if (!t1 and t2 and t4)cnt += goDp(i + 1, 1, 0, n);
        
        return dp[i][state] = cnt % mod;


    }

    ll numTilings(ll n) {
        memset(dp, -1, sizeof(dp));
        return goDp(0,1,1,n);
    }
};