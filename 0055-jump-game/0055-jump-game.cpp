class Solution {
public:
    #define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 1e6 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()
bool canJump(vector<int> &nums) {
    AboRadwan;
    reverse(all(nums));
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == 0) {
            ++cnt;
        } else {
            if (cnt > 0) {
                if (nums[i] > cnt)cnt = 0;
                else ++cnt;
            }
        }
    }
    return cnt == 0;
}
};