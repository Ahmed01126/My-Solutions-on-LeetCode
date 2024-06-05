class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
    int n = words.size();
    unordered_map<char, vector<int>> ump;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < 27; ++j)
            ump[j + 'a'].push_back(0);
    }
    for (int i = 0; i < words.size(); ++i) {
        for (auto j: words[i]) {
            ump[j][i]++;
        }
    }
    vector<string> ans;
    for (auto i: ump) {
        int mn = 1e9;
        for (auto j: i.second) {
            mn = min(mn, j);
        }
        
        while (mn--){
            string s = "";
            s += i.first;
            if(s!="")ans.push_back(s);
        }
    }
    return ans;
}
};