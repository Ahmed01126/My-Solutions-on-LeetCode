class Solution {
public:
    
#define ll long long
const ll N = 25, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()
int maxIceCream(vector<int>& costs, int coins) {
    sort(all(costs));
    int cnt=0;
    for (int i = 0; i < costs.size(); ++i) {
        if(coins>=costs[i])++cnt,coins-=costs[i];
        else break;
    }
    return cnt;
}
};