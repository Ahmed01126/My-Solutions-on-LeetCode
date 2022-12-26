class Solution {
public:
    #define AboRadwan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll N = 1e6 + 50, NN = 105, mod = 1e9 + 7;
#define all(v)        v.begin(), v.end()

int jump(vector<int> &nums) {
    AboRadwan;
    int n = nums.size();
    queue<int> q;
    q.push(0);
    vector<int> v(n, 1e9);
    v[0]=0;
    //[3,3,2,5,7,1,1,1,0,1]
    int i = 1;
    while (!q.empty()) {
        if (q.front() == n - 1)return v[q.front()] ;
        int x = nums[q.front()];
        for (int j = i-q.front(); j <= x; ++j) {
            if (j + q.front() >= n - 1)return v[q.front()] + 1;
            if(v[j + q.front()]==1e9)q.push(j + q.front());
            v[j + q.front()] = min(v[j + q.front()],v[q.front()] + 1);
            i = j + q.front();
        }
        
        q.pop();
    }
    return v[n - 1];
}
};