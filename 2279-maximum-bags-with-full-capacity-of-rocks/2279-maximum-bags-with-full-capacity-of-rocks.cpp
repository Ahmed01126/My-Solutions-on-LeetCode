class Solution {
public:
    
#define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 5e4 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    vector<int>diff;
    for (int i = 0; i < rocks.size(); ++i) {
        diff.push_back(abs(capacity[i]-rocks[i]));
    }
    sort(all(diff));
    int cnt=0;
    for (int i = 0; i < diff.size(); ++i) {
        if(diff[i]<=additionalRocks)++cnt,additionalRocks-=diff[i];
    }
    return cnt;
}
};