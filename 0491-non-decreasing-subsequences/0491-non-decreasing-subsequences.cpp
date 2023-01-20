class Solution {
public:
    void backtrack(int i, int n, vector<int> &v, set<vector<int>> &s, vector<int> x = {}) {
    if (i == n)return;
    if (x.empty() || v[i] >= x.back()) {
        x.push_back(v[i]);
        backtrack(i + 1, n, v, s, x);
        if(x.size()>1)s.insert(x);
        x.pop_back();
    }
    backtrack(i + 1, n, v, s, x);
    
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
    set<vector<int>> s;
    backtrack(0, nums.size(), nums, s);
    vector<vector<int>>v;
    for(auto i : s)v.push_back(i);
    return v;
}
};