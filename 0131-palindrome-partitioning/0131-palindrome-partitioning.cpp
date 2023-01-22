class Solution {
public:
    bool isPalindrome(string &s, int low, int high) {
    while (low < high) {
        if (s[low++] != s[high--]) return false;
    }
    return true;
}

void backtracking(vector<vector<string>> &v, int i, string &s, vector<string> &vs) {
    if(i>=s.size())
        v.push_back(vs);
    for (int j = i; j < s.size(); ++j) {
        if (isPalindrome(s, i, j)) {
            vs.push_back(s.substr(i, j - i + 1));
            backtracking(v, j + 1, s, vs);
            vs.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>>v;
    vector<string >vs;
    backtracking(v,0,s,vs);
    return v;
}
};