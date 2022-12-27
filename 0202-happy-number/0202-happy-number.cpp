class Solution {
public:
    #define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 5e4 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

bool isHappy(int n) {
    while (true) {
        int x = 0;
        while (n > 0) {
            x += (n % 10) * (n % 10);
            n /= 10;
        }
        n = x;
        if (n == 1 || n == 7)return 1;
        else if (n < 10)return 0;
    }
}
};