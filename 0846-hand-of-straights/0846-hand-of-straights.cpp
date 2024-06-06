class Solution {
public:
    bool isNStraightHand(vector<int> &v, int groupSize) {
    int n = v.size();
    if (n % groupSize != 0)return 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[v[i]]++;
    }
    int numOfGroups = n / groupSize;
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    for (int i = 0; i < numOfGroups; ++i) {
        if (v.empty())return 0;
        int x = v.back();
        for (int j = 0; j < groupSize; ++j) {
            if (mp[x] == 0)return 0;
            // cout << x <<" ";
            mp[x]--;
            ++x;
        }
        while (!v.empty() && mp[v.back()]==0)v.pop_back();
    }
    return 1;
}
};