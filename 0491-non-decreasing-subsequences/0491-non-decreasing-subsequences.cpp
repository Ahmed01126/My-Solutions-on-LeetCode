class Solution {
public:
    set<vector<int>> s;
    void backtrack(int i, const int n, const vector<int> &v, vector<int> &x) {
    if (i == n)return;
    if (x.empty() || v[i] >= x.back()) {
        x.push_back(v[i]);
        backtrack(i + 1, n, v, x);
        if(x.size()>1)s.insert(x);
        x.pop_back();
    }
    backtrack(i + 1, n, v,  x);
    
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
    // set<vector<int>> s;
    vector<int>x;
    backtrack(0, nums.size(), nums,x);
    return vector(s.begin(),s.end());
}
};