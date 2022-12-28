class Solution {
public:
    #define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 5e4 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

string multiply(string num1, string num2) {
    string ans = "";
    reverse(all(num1));
    reverse(all(num2));
    for (ll i = 0; i < num1.size(); ++i) {
        string s = string(i, '0');
        ll cary = 0;
        for (ll j = 0; j < num2.size(); ++j) {
            ll x = num1[i] - '0', y = num2[j] - '0';
            ll m = x * y + cary;
            s += (m % 10 + '0'), cary = m / 10;
        }
        s += (cary + '0');

//        cout << s << endl;
        if (ans.empty())ans = s;
        else {
            ll cary = 0;
            string x = "";
            for (int j = 0; j < max(ans.size(), s.size()); ++j) {
                ll xx = j < ans.size() ? ans[j] - '0' : 0, y = j < s.size() ? s[j] - '0' : 0;
                ll m = xx + y + cary;
                x += (m % 10 + '0'), cary = m / 10;
            }
            x += (cary + '0');
            ans = x;
        }
//        cout << "ans = > " << ans << endl;
    }
    while (ans.size()!=1&&ans.back()=='0')ans.pop_back();
    reverse(all(ans));
    return ans;

}
};