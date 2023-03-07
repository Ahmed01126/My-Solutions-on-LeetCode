class Solution {
public:
    #define ll long long

    bool check(ll x, vector<int> &v, int sum) {
    ll cnt = 0;
    for (auto i : v) {
        cnt += x / i;
        if (cnt >= sum)return 1;

    }
    if (cnt >= sum)return 1;
    return 0;
}

long long minimumTime(vector<int> &time, int totalTrips) {
    ll s = 0, e = 1e18, mid, ans = 0;
    while (s <= e) {
        mid = (s + e) >> 1;
        if (check(mid, time, totalTrips)) {
            ans = mid;
            e = mid - 1;
        } else s = mid + 1;
    }
    return ans;
}
};