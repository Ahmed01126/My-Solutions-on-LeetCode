class Solution {
public:
#define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 25, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

int longestPalindrome(vector<string> &words) {
    map<string, int> mp;
    for (auto i : words)mp[i]++;
    int ans = 0;
    bool z = 0;
    for (int i = 0; i < words.size(); ++i) {
        string s = words[i];
        reverse(all(s));
        if (mp[s] > 0) {
            if (s[0] == s[1]) {
                if (mp[s] % 2 == 0)ans += 2 * mp[s];
                else z = 1, ans += 2 * (mp[s] - 1);
            } else {
                ans+=min(mp[s],mp[words[i]])*4;
            }
            mp[s] = 0, mp[words[i]] = 0;
        }
    }
    return ans+z*2;
}
};