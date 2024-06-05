class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
    int n = words.size();
    vector<string> ans;
    int freq[27][n + 1];
    for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            freq[i][j] = 0;
        }
    }
    for (int i = 0; i < 27; ++i) {
        int mn = 1e9;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < words[j].size(); ++k) {
                if (i == words[j][k] - 'a')freq[i][j]++;
            }
            mn = min(mn, freq[i][j]);
        }
        while (mn > 0) {
            mn--;
            string s = "";
            s += i + 'a';
            ans.push_back(s);
        }
    }
    return ans;
}
};